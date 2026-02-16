#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int reverseBits(int n) {
        int ans = 0, cnt = 31;
        while (cnt >= 0) {
            ans += (n % 2) * pow(2, cnt--);
            n /= 2;
        }
        return ans;
    }
};

int main() {
    uint32_t n = 43261596;
    cout << Solution().reverseBits(n) << endl;
	return 0;
}