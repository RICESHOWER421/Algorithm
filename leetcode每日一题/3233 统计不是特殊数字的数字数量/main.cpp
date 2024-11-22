#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

//灵神代码，只能说思路是想到了但是代码优化问题还得多考虑
//之前是用欧拉筛+遍历写，但是时间复杂度为O(N)也是超了
//所以需要使用灵神的预处理+O(1)出答案的思路
//这道题wa了11次，思路完全没有问题，结果就卡在案例能过提交却不能过
//改了老半天才发现是自己O(N)超了，只能说气死了
const int MX = 31622;
int pi[MX + 1];

auto init = [] {
    for (int i = 2; i <= MX; i++) {
        if (pi[i] == 0) { 
            pi[i] = pi[i - 1] + 1;
            for (int j = i * i; j <= MX; j += i) { 
                pi[j] = -1; 
            }
        }
        else {
            pi[i] = pi[i - 1];
        }
    }
    return 0;
}();

class Solution {
public:
    int nonSpecialCount(int l, int r) {
        return r - l + 1 - (pi[(int)sqrt(r)] - pi[(int)sqrt(l - 1)]);
    }
};

int main() {
    cout << Solution().nonSpecialCount(10, 11) << "\n";
	return 0;
}