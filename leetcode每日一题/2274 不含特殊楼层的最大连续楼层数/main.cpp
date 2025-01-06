#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        int mx = special[0] - bottom;
        for (int i = 1; i < special.size(); i++) {
            mx = max(mx, special[i] - special[i - 1] - 1);
        }
        return max(mx, top - special.back());
    }
};

int main() {

	return 0;
}