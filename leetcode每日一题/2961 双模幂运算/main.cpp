#include <iostream>
#include <vector>
using namespace std;

//快速幂版本
int my_pow(int x, int y, int mod) {
    int res = 1;
    while (y) {
        if (y & 1) {
            res = res * x % mod;
        }
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}

//递归版本
int my_pow(int x, int y, int mod) {
    if (y == 0) return 1;

    int temp = my_pow(x, y / 2, mod);
    return y % 2 == 0 ? temp * temp % mod : temp * temp * x % mod;
}

vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
    vector<int> ret;
    for (int i = 0; i < variables.size(); i++)
        if (my_pow(my_pow(variables[i][0], variables[i][1], 10), variables[i][2], variables[i][3]) == target) ret.push_back(i);
    return ret;
}

int main() {

    return 0;
}