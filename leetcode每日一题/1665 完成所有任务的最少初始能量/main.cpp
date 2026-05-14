#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [&](const vector<int>& a, const vector<int>& b) {
            return a[1] - a[0] > b[1] - b[0];
            });

        int ans = 0, s = 0;
        for (auto& x : tasks) {
            ans = max(ans, s + x[1]);
            s += x[0];
        }
        return ans;
    }
};

int main() {

	return 0;
}