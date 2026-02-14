#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> nums(100, vector<double>(100));
        queue<pair<int, int>> q;
        q.push({ 0,0 });
        nums[0][0] = poured;
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            if (x >= 99 || y >= 99) continue;
            if (nums[x][y] >= 1) {
                double ret = (nums[x][y] - 1) / 2;
                if (ret && !nums[x + 1][y]) q.push({ x + 1, y });
                nums[x + 1][y] += ret;
                if (ret && !nums[x + 1][y + 1]) q.push({ x + 1, y + 1 });
                nums[x + 1][y + 1] += ret;
                nums[x][y] = 1;
            }
        }
        return nums[query_row][query_glass];
    }
};

int main() {
    cout << Solution().champagneTower(1, 1, 1) << "\n";
	return 0;
}