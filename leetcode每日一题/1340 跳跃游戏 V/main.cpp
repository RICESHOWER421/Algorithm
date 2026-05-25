#include <bits/stdc++.h>
using namespace std;
//初版bfs写法，暴力过了
class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size(), ans = 1;
        vector<int> cnts(n, -1);
        auto bfs = [&](int pos)->void {
            queue<int> q;
            q.push(pos);
            cnts[pos] = 1;
            while (!q.empty()) {
                int p = q.front();
                q.pop();

                //朝左走
                for (int i = p - 1; i >= max(0, p - d); i--) {
                    if (arr[i] < arr[p]) {    //可以跳过
                        if (cnts[p] + 1 > cnts[i]) {
                            cnts[i] = cnts[p] + 1;
                            q.push(i);
                        }
                    }
                    else break;
                }

                //朝右走
                for (int i = p + 1; i <= min(n - 1, p + d); i++) {
                    if (arr[i] < arr[p]) {    //可以跳过
                        if (cnts[p] + 1 > cnts[i]) {
                            cnts[i] = cnts[p] + 1;
                            q.push(i);
                        }
                    }
                    else break;
                }
            }
        };

        for (int i = 0; i < n; i++) {
            if (cnts[i] == -1) bfs(i);
        }
        for (int i = 0; i < n; i++) ans = max(ans, cnts[i]);
        return ans;
    }
};

//dfs写法
class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> memo(n, 1);

        auto dfs = [&](this auto&& dfs, int pos)->int {
            //朝左边走
            for (int i = pos - 1; i >= max(0, pos - d); i--) {
                if (arr[i] < arr[pos]) {
                    if (memo[i] == 1) memo[pos] = max(memo[pos], dfs(i) + 1);
                    else memo[pos] = max(memo[pos], memo[i] + 1);
                }
                else break;
            }

            //朝右边走
            for (int i = pos + 1; i <= min(n - 1, pos + d); i++) {
                if (arr[i] < arr[pos]) {
                    if (memo[i] == 1) memo[pos] = max(dfs(i) + 1, memo[pos]);
                    else memo[pos] = max(memo[pos], memo[i] + 1);
                }
                else break;
            }
            return memo[pos];
        };

        for (int i = 0; i < n; i++) {
            if (memo[i] == 1) dfs(i);
        }
        int ans = 1;
        for (auto& x : memo) {
            ans = max(ans, x);
        }
        return ans;
    }
};

int main() {

	return 0;
}
