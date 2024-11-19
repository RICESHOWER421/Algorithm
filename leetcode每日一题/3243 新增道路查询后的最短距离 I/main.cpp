#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<vector<int>> hash_map(501, vector<int>());
        
        for (int i = 0; i < n; i++) {
            hash_map[i].push_back(i + 1);
        }

        int m = queries.size();
        for (int i = 0; i < m; i++) {
            vector<bool> dist(n);
            hash_map[queries[i][0]].push_back(queries[i][1]);
            int count = 0;
            bool ok = false;
            queue<int> q;
            q.push(0);
            while (!q.empty()) {
                int ret = q.size();
                while (ret--) {
                    int pos = q.front();
                    q.pop();

                    dist[pos] = true;
                    if (pos == n - 1) {
                        ok = true;
                        ans.push_back(count);
                        break;
                    }

                    for (auto& x : hash_map[pos]) {
                        if(!dist[x]) q.push(x);
                    }
                }
                if (ok) break;
                ++count;
            }
        }
        return ans;
    }
};

int main() {
    int n = 5;
    vector<vector<int>> queries = { {2,4}, {0,2} , {0,4} };
    vector<int> ans = Solution().shortestDistanceAfterQueries(n,queries);
    for (auto& x : ans) {
        cout << x << " ";
    }
    cout << "\n";
    return 0; 
}