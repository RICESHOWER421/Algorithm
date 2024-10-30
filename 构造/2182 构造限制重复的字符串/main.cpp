#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> hash_map(27);
        for (auto& x : s) {
            hash_map[x - 'a']++;
        }

        string ans;
        int right = 26, left = 26;
        while (left >= 0 && right >= 0) {
            int index = 0;
            while (!hash_map[right] || left == right) {
                --right;
                if (right < 0) {
                    index = 1;
                    break;
                }
            }
            if (index) break;
            while (!hash_map[left] || left == right) {
                --left;
                if (left < 0) {
                    index = 1;
                    break;
                }
            } 
            if (index) break;
            if (right < left) swap(left, right);
            while (hash_map[right] && hash_map[left]) {
                bool ok = !ans.empty() && ans.back() == right + 'a';
                if (ok) {
                    for (int i = 0; i < (hash_map[right] >= repeatLimit - 1 ? repeatLimit - 1 : hash_map[right]); i++) {
                        ans += (right + 'a');
                    }
                    hash_map[right] -= (hash_map[right] >= repeatLimit - 1 ? repeatLimit - 1 : hash_map[right]);
                    ok = false;
                }
                else {
                    for (int i = 0; i < (hash_map[right] >= repeatLimit ? repeatLimit : hash_map[right]); i++) {
                        ans += (right + 'a');
                    }
                    hash_map[right] -= (hash_map[right] >= repeatLimit ? repeatLimit : hash_map[right]);
                }
                ans += (left + 'a');
                hash_map[left]--;
            }
        }
        
        if (ans.empty()) {
            for (int i = 0; i < min(hash_map[right], repeatLimit); i++) {
                ans += (right + 'a');
            }
        }
        else {
            if (left < 0) {
                for (int i = 0; i < min(repeatLimit, hash_map[right]); i++) {
                    ans += (right + 'a');
                }
            }
            else {
                for (int i = 0; i < min(repeatLimit - 1, hash_map[left]); i++) {
                    ans += (left + 'a');
                }
            }
        }
        return ans;
    }
};

int main() {
    string ret = "robnsdvpuxbapuqgopqvxdrchivlifeepy";
    string ans = Solution().repeatLimitedString(ret, 2);
    cout << ans << "\n";
	return 0;
}