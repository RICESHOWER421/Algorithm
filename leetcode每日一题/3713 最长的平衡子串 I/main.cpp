#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int ans = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            vector<int> hash_map(26);
            bool ok = true;
            for (int j = i; j < n; j++) {
                int tmp = ++hash_map[s[j] - 'a'];
                for (auto& x : hash_map) {
                    if (x && x != tmp) {
                        tmp = -1;
                        break;
                    }
                }
                if (tmp != -1) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};

int main() {

	return 0;
}