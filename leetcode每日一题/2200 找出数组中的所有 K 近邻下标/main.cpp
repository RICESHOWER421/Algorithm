#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> diff(n), ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] == key) {
                diff[max(0, i - k)]++;
                if (i + k + 1 < n) diff[i + k + 1]--;
            }
        }
        if (diff[0]) ans.push_back(0);
        for (int i = 1; i < n; i++) {
            diff[i] += diff[i - 1];
            if (diff[i]) ans.push_back(i);
        }
        return ans;
    }
};

int main() {
	
	return 0;
}