#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        int mx = -1;
        for (int i = 0; i < num.size() - 2; i++) {
            if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
                if (num[i] - '0' > mx) {
                    mx = num[i] - '0';
                }
            }
        }

        if (mx == -1) {
            return "";
        }
        else {
            string ans;
            for (int i = 0; i < 3; i++) {
                ans += (mx + '0');
            }
            return ans;
        }
    }
};

int main() {

	return 0;
}