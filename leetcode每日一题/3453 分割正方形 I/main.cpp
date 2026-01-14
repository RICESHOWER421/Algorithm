#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

/*
* 浮点二分，设区间长度为L，二分一次减小一半，所以有：
* L / pow(2, k) <= 1e5
* k >= log2(L * 1e5)
* 本题k值取47，48即可
*/
using ll = long long;
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double left = 1e10, right = 0, ans = 1e15;
        for (auto& x : squares) {
            left = min(left, (double)x[1]);
            right = max(right, (double)((ll)x[1] + x[2]));
        }

        for (int i = 0; i <= 47; i++) {
            double up = 0, down = 0;
            double tmp = left + (right - left) / 2;
            for (auto& x : squares) {
                double t1 = (ll)x[1] + x[2];
                if (t1 > tmp) {
                    if (x[1] < tmp) {//切线在正方形中间
                        up += (t1 - tmp) * (double)x[2];
                        down += (tmp - (double)x[1]) * (double)x[2];
                    }
                    else {
                        up += pow((double)x[2], 2);
                    }
                }
                else {
                    down += pow((double)x[2], 2);
                }
            }
            if (up > down) {
                left = tmp;
            }
            else {
                if (abs(up - down) <= 1e5) ans = min(ans, tmp);
                right = tmp;
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> s = { {0,0,2}, {1,1,1} };
    printf("%.5lf", Solution().separateSquares(s));
	return 0;
}