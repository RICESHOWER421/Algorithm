#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int ans = 0;
        vector<int> t1 = nums, t2;
        while (true) {
            bool ok = true;
            int n = t1.size(), mn = t1[0] + t1[1], index = 0;
            for (int i = 1; i < n; i++) {
                if (t1[i] < t1[i - 1]) {
                    ok = false;
                    break;
                }
            }
            if (ok) break;

            ++ans;
            for (int i = 0; i < n - 1; i++) {
                if (t1[i] + t1[i + 1] < mn) {
                    mn = t1[i] + t1[i + 1];
                    index = i;
                }
            }

            for (int i = 0; i < n; i++) {
                if (i != index) t2.push_back(t1[i]);
                else {
                    t2.push_back(mn);
                    ++i;
                }
            }
            t1 = t2;
            t2.clear();
        }
        return ans;
    }
};

int main() {
    vector<int> nums = { 2,2,-1,3,-2,2,1,1,1,0,-1 };
    cout << Solution().minimumPairRemoval(nums) << "\n";
	return 0;
}