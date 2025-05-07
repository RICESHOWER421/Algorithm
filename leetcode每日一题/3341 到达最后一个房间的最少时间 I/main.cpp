#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        dist[0][0] = 0;
        pq.push({ 0,0,0 });
        while (true) {
            auto tmp = pq.top();
            pq.pop();

            int x = get<1>(tmp), y = get<2>(tmp), len = get<0>(tmp);
            if (x == n - 1 && y == m - 1) {
                return len;
            }
            if (len > dist[x][y]) {     //当前的路径并不是最优路径，则直接退出即可
                continue;
            }

            for (int i = 0; i < 4; i++) {
                int px = x + dx[i], py = y + dy[i];
                if (px >= 0 && px < n && py >= 0 && py < m) {
                    int new_len = max(len, moveTime[px][py]) + 1;
                    if (new_len < dist[px][py]) {
                        dist[px][py] = new_len;
                        pq.push({ new_len, px, py });
                    }
                }
            }
        }
    }
};

int main() {
    /*vector<vector<int>> nums = { {0,0}, {0,0} };
    cout << Solution().minTimeToReach(nums) << "\n";*/
	return 0;
}