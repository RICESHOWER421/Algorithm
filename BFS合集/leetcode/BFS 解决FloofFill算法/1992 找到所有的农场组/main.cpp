#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
void bfs(int x, int y, vector<vector<int>>& land, vector<vector<bool>>& vis, vector<int>& ret) {
    ret.push_back(x);
    ret.push_back(y);
    
    int m = land.size(), n = land[0].size();
    queue<pair<int,int>> q;
    q.push({x,y});
    while (!q.empty()) {
        pair<int, int> arr = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = arr.first + dx[i], y = arr.second + dy[i];
            if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && land[x][y] == 1) {
                q.push({ x,y });
                vis[x][y] = true;
            }
        }
        if (q.empty()) {
            ret.push_back(arr.first);
            ret.push_back(arr.second);
        }
    }
}

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n));
        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] == 1 && !vis[i][j]) {
                    vector<int> ret;
                    bfs(i, j, land, vis, ret);
                    ans.push_back(ret);
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> land = { {1,1},{0,0} };
    vector<vector<int>> ans = Solution().findFarmland(land);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << " " << ans[i][3] << "\n";
    }
	return 0;
}