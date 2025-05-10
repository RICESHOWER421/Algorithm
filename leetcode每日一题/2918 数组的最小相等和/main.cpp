#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        ll s1 = 0, s2 = 0, cnt1 = 0, cnt2 = 0;
        for (auto& x : nums1) {
            if (!x) ++cnt1;
            s1 += x;
        }
        for (auto& x : nums2) {
            if (!x) ++cnt2;
            s2 += x;
        }

        // cout << s1 << " " << s2 << "\n";
        // cout << cnt1 << " " << cnt2 << "\n";
        if (cnt1 && cnt2) {
            return max(s1 + cnt1, s2 + cnt2);
        }
        else if (cnt1 && !cnt2) {
            if (s1 >= s2) return -1;
            else return (s2 - s1 >= cnt1 ? s2 : -1);
        }
        else if (!cnt1 && cnt2) {
            if (s2 >= s1) return -1;
            else return (s1 - s2 >= cnt2 ? s1 : -1);
        }
        else {
            return (s1 == s2 ? s1 : -1);
        }
    }
};

int main() {

	return 0;
}