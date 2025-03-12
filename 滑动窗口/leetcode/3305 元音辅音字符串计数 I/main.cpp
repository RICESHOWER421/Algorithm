#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judge(string ret, vector<int>& arrs) {
        for (auto& x : ret) {
            if (!arrs[x - 'a']) {
                return false;
            }
        }
        return true;
    }

    //��ʾ�ַ����и�����ĸ���ٳ���k�ε����ַ�������
    int func(string word, int k) {
        string ret = "aeiou";
        vector<int> arrs(26);
        int l = 0, r = 0, cnt = 0, ans = 0;

        auto change = [&](char a, bool ok) -> void {
            bool tmp = false;
            for (auto& x : ret) {
                if (a == x) {
                    arrs[x - 'a'] += (ok ? 1 : -1);
                    tmp = true;
                    break;
                }
            }

            if (!tmp) {
                cnt += (ok ? 1 : -1);
            }
        };

        while (r < word.size()) {
            change(word[r], true);
            ++r;

            while (judge(ret, arrs) && cnt >= k) {
                change(word[l], false);
                ++l;
            }
            ans += l;
        }
        return ans;
    }

    int countOfSubstrings(string word, int k) {
        return func(word, k) - func(word, k + 1);
    }
};

int main() {
    string s = "aeioqq";
    cout << Solution().countOfSubstrings(s, 1) << "\n";
	return 0;
}