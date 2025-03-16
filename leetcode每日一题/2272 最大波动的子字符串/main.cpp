#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestVariance(string s) {
        int ans = 0;
        for (char i = 'a'; i <= 'z'; i++) {
            for (char j = 'a'; j <= 'z'; j++) {
                if (i == j) {
                    continue;
                }

                //r1表示无论是否存在b都行，r2表示一定要有b
                int r1 = 0, r2 = -0x3f3f3f3f;
                for (auto& x : s) {
                    if (x == i) {
                        r1 = max(r1, 0) + 1;
                        r2++;
                    }
                    else if (x == j) {
                        r1 = max(r1, 0) - 1;
                        r2 = r1;
                    }
                    ans = max(ans, r2);
                }
            }
        }
        return ans;
    }
};

int main() {

	return 0;
}