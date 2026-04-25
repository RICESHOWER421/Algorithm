#include <bits/stdc++.h>
using namespace std;

/*
二分答案
难点在于 ：
1、矩形问题转换为直线问题
2、如何枚举所有情况
难点说实话都能想得到，但是就是在实现上稍微犯了难
一开始还给出了正负轴，其实可以直接确定一个起点设置为0点给正轴即可
然后就是枚举每个初始点然后选择k个点，灵神这种写法真的牛，写的太妙了
*/

class Solution {
public:
    using ll = long long;
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<ll> idx;
        //将矩阵问题转换为直线问题
        for (auto& p : points) {
            int x = p[0], y = p[1];
            if (x == 0) {
                idx.push_back(y);
            }
            else if (y == side) {
                idx.push_back(side + x);
            }
            else if (x == side) {
                idx.push_back((ll)side * 3 - y);
            }
            else {
                idx.push_back((ll)side * 4 - x);
            }
        }
        sort(idx.begin(), idx.end());

        auto check = [&](int mid)->bool {
            vector<int> nums(k);
            while (true) {    //枚举从每个点开始，选择k个点判断是否可行，不得不说这种写法绝了
                for (int i = 1; i < k; i++) {
                    while (idx[nums[i]] < idx[nums[i - 1]] + mid) {
                        ++nums[i];
                        if (nums[i] == idx.size()) {  //所有点都找了一遍发现没有满足要求的
                            return false;
                        }
                    }
                }
                if (idx[nums[k - 1]] - idx[nums[0]] <= (ll)side * 4 - mid) {
                    return true;
                }
                nums[0]++;
            }
        };

        //由于k >= 4,所以答案给出的最大值是side
        int l = 1, r = (ll)side * 4 / k;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};

int main() {

	return 0;
}