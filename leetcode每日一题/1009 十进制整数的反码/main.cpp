#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        int ans = 0, cnt = 0;
        while (n) {
            ans += (!(n % 2)) * pow(2, cnt++);
            n /= 2;
        }
        return ans;
    }
};

int main() {

	return 0;
}