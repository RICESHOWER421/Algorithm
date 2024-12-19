#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.size();
        vector<int> ret;

        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                ret.push_back(i);
                if (i != n / i) {
                    ret.push_back(n / i);
                }
            }
        }

        int ans = 0x3f3f3f3f;
        for (int i = 0; i < ret.size(); i++) {
            vector<int> hash_map(26);
            bool ok = true;
            for (int j = 0; j < n; j += ret[i]) {
                vector<int> nums(26);
                for (int k = j; k < j + ret[i]; k++) {
                    if (j == 0) {
                        hash_map[s[k] - 'a']++;
                    }
                    else {
                        nums[s[k] - 'a']++;
                    }
                }

                if (j) {
                    for (int k = 0; k < 26; k++) {
                        if (hash_map[k] != nums[k]) {
                            ok = false;
                            break;
                        }
                    }
                }
              
                if (!ok) {
                    break;
                }
            }
            if (ok) {
                ans = min(ans, ret[i]);
            }
        }
        return ans;
    }
};

int main() {
    string s = "abba";
    cout << Solution().minAnagramLength(s) << "\n";
	return 0;
}