#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<int> m = { 1,2,4,8,16,32 }, h = { 1,2,4,8 };
        vector<string> ans;
        vector<vector<string>> h_sum(5), m_sum(7);

        int sum = 0;
        auto dfs1 = [&](auto&& dfs1, int cnt, int cur, int pos)->void {
            if (cnt == pos) {
                if (sum <= 11) {
                    string tmp;
                    tmp += to_string(sum);
                    h_sum[pos].push_back(tmp);
                }
                return;
            }
            if (cur == 4) return; 

            for (int i = cur; i < 4; i++) {
                sum += h[i];
                dfs1(dfs1, cnt + 1, i + 1, pos);
                sum -= h[i];
            }
        };

        auto dfs2 = [&](auto&& dfs2, int cnt, int cur, int pos)->void {
            if (cnt == pos) {
                if (sum <= 59) {
                    string tmp;
                    if (sum >= 0 && sum <= 9) {
                        tmp += "0";
                        tmp += (sum + '0');
                    }
                    else tmp += to_string(sum);
                    m_sum[pos].push_back(tmp);
                }
                return;
            }
            if (cur == 6) return;

            for (int i = cur; i < 6; i++) {
                sum += m[i];
                dfs2(dfs2, cnt + 1, i + 1, pos);
                sum -= m[i];
            }
        };

        for (int i = 0; i <= 4; i++) {
            dfs1(dfs1, 0, 0, i);
        }
        for (int i = 0; i <= 6; i++) {
            dfs2(dfs2, 0, 0, i);
        }


        for (int i = 0; i <= 4; i++) {
            int num = turnedOn - i;
            if (num >= 0 && num <= 6) {
                for (auto& x : h_sum[i]) {
                    for (auto& y : m_sum[num]) {
                        string tmp = x + ":" + y;
                        ans.push_back(tmp);
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<string> ans = Solution().readBinaryWatch(2);
    for (auto& x : ans) {
        cout << x << "\n";
    }
	return 0;
}