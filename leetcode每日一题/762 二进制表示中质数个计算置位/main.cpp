#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        vector<int> nums = { 2,3,5,7,11,13,17,19,23,29,31 };
        for (int i = left; i <= right; i++) {
            int num = i, cnt = 0;
            while (num) {
                cnt += num % 2;
                num /= 2;
            }

            //优化，根据数据直接确定质数
            for (auto& x : nums) {
                if (cnt == x) {
                    ++ans;
                    break;
                }
            }
            // bool ok = true;
            // for(int j = 2; j <= sqrt(cnt); j++){
            //     if(cnt % j == 0){
            //         ok = false;
            //         break;
            //     }
            // }
            // ans += (cnt != 1 && ok);
        }
        return ans;
    }
};

int main() {

	return 0;
}