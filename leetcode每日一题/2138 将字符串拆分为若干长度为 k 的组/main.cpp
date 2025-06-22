#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int cnt = 0;
        string tmp;
        for (int i = 0; i < s.size(); i++) {
            if (cnt == k) {
                ans.push_back(tmp);
                tmp.clear();
                cnt = 0;
            }
            tmp += s[i];
            ++cnt;
        }
        ans.push_back(tmp);
        if (ans.back().size() != k) {
            while (ans.back().size() != k) {
                ans.back() += fill;
            }
        }
        return ans;
    }
};

int main() {

	return 0;
}