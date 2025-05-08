#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> ufs(26, -1);
        auto Find = [&](int x) -> int {
            while (ufs[x] >= 0) {
                x = ufs[x];
            }
            return x;
        };

        for (auto& x : equations) {
            if (x[1] == '=') {
                int r1 = Find(x[0] - 'a'), r2 = Find(x[3] - 'a');
                if (r1 != r2) {
                    ufs[r1] += ufs[r2];
                    ufs[r2] = r1;
                }
            }
        }
        for (auto& x : equations) {
            if (x[1] == '!' && Find(x[0] - 'a') == Find(x[3] - 'a')) {
                return false;
            }
        }
        return true;
    }
};

int main() {

	return 0;
}