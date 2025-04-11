#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int i = low; i <= high; i++) {
            string s = to_string(i);
            if (s.size() % 2 == 0) {
                int n = s.size(), r1 = 0, r2 = 0;
                for (int i = 0; i < n / 2; i++) {
                    r1 += (s[i] - '0');
                }
                for (int i = n / 2; i < n; i++) {
                    r2 += (s[i] - '0');
                }
                ans += r1 == r2;
            }
        }
        return ans;
    }
};

int main() {

	return 0;
}