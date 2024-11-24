#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumLength(string s) {
        int left = 0, right = s.size();
        while (left < right) {
            int mid = left + (right - left + 1) / 2;

            int sum = 0, l = 0, r = 0;
            vector<int> count(26), hash_map(26);
            while (r - l < mid) {
                count[s[r++] - 'a']++;
            }

            bool ok = false;
            while (r < s.size()) {
                if (count[s[r - 1] - 'a'] == mid) {
                    hash_map[s[r - 1] - 'a']++;
                    if (hash_map[s[r - 1] - 'a'] >= 3) {
                        ok = true;
                        break;
                    }
                }

                if (sum >= 3) {
                    ok = true;
                    break;
                }
                count[s[r++] - 'a']++;
                count[s[l++] - 'a']--;
            }

            if (count[s[r - 1] - 'a'] == mid) {
                hash_map[s[r - 1] - 'a']++;
                if (hash_map[s[r - 1] - 'a'] >= 3) ok = true;
            }

            if (ok) left = mid;
            else right = mid - 1;
        }
        return left == 0 ? -1 : left;
    }
};

int main() {
    string s = "abcdef";
    cout << Solution().maximumLength(s) << "\n";
	return 0;
}