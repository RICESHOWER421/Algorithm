#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> nums(26), rets;
        for (auto& x : word) {
            nums[x - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (nums[i]) rets.push_back(nums[i]);
        }
        sort(rets.begin(), rets.end(), greater<int>());

        int ans = 0x3f3f3f3f, ret = 0;
        for (int i = rets.size() - 1; i >= 0; i--) {
            int sum = 0;
            for (int j = 0; j < i; j++) {
                if (rets[j] - rets[i] > k) sum += (rets[j] - rets[i] - k);
                else break;
            }
            ans = min(ans, sum + ret);
            ret += rets[i];
        }
        return ans;
    }
};

int main() {

	return 0;
}