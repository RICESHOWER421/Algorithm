#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    bool check(vector<int>& nums1, vector<int>& nums2) {
        for (int i = 0; i < 26; i++) {
            if (nums2[i] < nums1[i]) {
                return false;
            }
        }
        return true;
    }

    long long validSubstringCount(string word1, string word2) {
        ll ans = 0;
        int n = word1.size();
        vector<int> tmp(26), nums(26);
        for (auto& x : word2) {
            tmp[x - 'a']++;
        }

        int l = 0, r = 0;
        while (r < n) {
            nums[word1[r] - 'a']++;
            if (check(tmp, nums)) {
                while (check(tmp, nums)) {
                    ans += n - r;
                    nums[word1[l] - 'a']--;
                    ++l;
                }
            }
            ++r;
        }
        return ans;
    }
};


int main() {

	return 0;
}