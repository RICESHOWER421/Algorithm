#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = INT_MAX, n = tops.size();
        auto check = [&](bool ok, int num) -> int {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (ok) {
                    if (tops[i] != num) {
                        if (bottoms[i] == num) {
                            ++cnt;
                        }
                        else {
                            return -1;
                        }
                    }
                }
                else {
                    if (bottoms[i] != num) {
                        if (tops[i] == num) {
                            ++cnt;
                        }
                        else {
                            return -1;
                        }
                    }
                }
            }
            return cnt;
        };

        for (int i = 1; i <= 6; i++) {
            int n1 = check(true, i);
            if (n1 != -1) ans = min(ans, n1);
            int n2 = check(false, i);
            if (n2 != -1) ans = min(ans, n2);
        }
        return (ans == INT_MAX ? -1 : ans);
    }
};

int main() {

	return 0;
}