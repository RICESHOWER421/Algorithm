#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dx[4] = { 0,0,-1,1 }, dy[4] = {-1,1,0,0};
    bool check(int ans, vector<vector<int>>& nums) {
        int n = nums.size(), m = nums[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));
        queue<pair<int, int>> q;
        vis[0][0] = true;
        q.push({0,0});
        
        int mx = -1;
        while(!q.empty()){
            pair<int, int> pos = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int x = pos.first + dx[i], y = pos.second + dy[i];
                if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && abs(nums[x][y] - nums[pos.first][pos.second]) <= ans) {
                    q.push({x, y});
                    vis[x][y] = true;
                }
            }
        }
        return vis[n - 1][m - 1];
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int left = 0, right = 1e6 + 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (check(mid, heights)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};

int main() {

	return 0;
}