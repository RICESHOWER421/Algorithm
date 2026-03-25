#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        unordered_map<ll, int> c1, c2; //c1表示上（左）半部分，c2表示下（右）半部分
        ll sum = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum += grid[i][j];
                c2[grid[i][j]]++;
            }
        }

        ll tmp = 0;
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                tmp += grid[i][j];
                c2[grid[i][j]]--;
                c1[grid[i][j]]++;
            }

            ll l = tmp, r = sum - tmp;
            if (l > r) {
                ll ret = l - r;
                if (n == 1 || m == 1) {     //如果只有一列或者一行，那么只能删除上半部分的第一个数和最后一个数
                    if (grid[0][0] == ret || grid[i][0] == ret) return true;
                }
                else {
                    if (i == 0) {     //上半部分只有第一行时，只能删除第一个数或者最后一个数
                        if (grid[0][0] == ret || grid[0].back() == ret) return true;
                    }
                    else {
                        if (c1[ret]) return true;
                    }
                }
            }
            else if (l < r) {
                ll ret = r - l;
                if (n == 1 || m == 1) { //如果只有一行或者一列，那么只能删除下半部分的第一个数和最后一个数
                    if (grid[m - 1][0] == ret || grid[i + 1][0] == ret) return true;
                }
                else {
                    if (i == m - 2) { //下半部分只有最后一行时，只能删除第一个数或者最后一个数
                        if (grid[m - 1][0] == ret || grid[m - 1].back() == ret) return true;
                    }
                    else {
                        if (c2[ret]) return true;
                    }
                }
            }
            else return true;
        }

        swap(c1, c2);
        tmp = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m; j++) {
                tmp += grid[j][i];
                c2[grid[j][i]]--;
                c1[grid[j][i]]++;
            }

            ll l = tmp, r = sum - tmp;
            if (l > r) {
                ll ret = l - r;
                if (m == 1 || n == 1) { //如果只有一行或者一列，只能删除左半部分第一个数和最后一个数
                    if (grid[0][0] == ret || grid[0][i] == ret) return true;
                }
                else {
                    if (i == 0) {     //左半部分只有第一列时,只能删除第一个和最后一个数
                        if (ret == grid[0][0] || ret == grid[m - 1][0]) return true;
                    }
                    else {
                        if (c1[ret]) return true;
                    }
                }
            }
            else if (l < r) {
                ll ret = r - l;
                if (m == 1 || n == 1) { //如果只有一行或者一列，只能删除右半部分第一个数和最后一个数
                    if (grid[0].back() == ret || grid[0][i + 1] == ret) return true;
                }
                else {
                    if (i == n - 2) { //右半部分只有最后一列时，只能删除第一个数和最后一个数
                        if (ret == grid[0].back() || ret == grid[m - 1].back()) return true;
                    }
                    else {
                        if (c2[ret]) return true;
                    }
                }
            }
            else return true;
        }
        return false;
    }
};

int main() {

	return 0;
}