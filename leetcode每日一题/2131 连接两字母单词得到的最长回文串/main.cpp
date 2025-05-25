#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0, more = 0;
        map<string, int> hash_map;
        for (auto& x : words) {
            hash_map[x]++;
        }

        for (auto& [a, b] : hash_map) {
            if (a[0] == a[1]) {
                if (hash_map[a] % 2) more = max(more, hash_map[a]);
            }
            else {
                string tmp = a;
                swap(tmp[0], tmp[1]);
                ans += min(hash_map[tmp], hash_map[a]) * 4;
            }
        }
        ans /= 2;

        bool ok = true;
        for (auto& [a, b] : hash_map) {
            if (a[0] == a[1]) {
                if (hash_map[a] % 2 == 0) ans += hash_map[a] * 2;
                else {
                    if (hash_map[a] == more) {
                        if (ok) {
                            ok = false;
                            ans += hash_map[a] * 2;
                        }
                        else {
                            ans += (hash_map[a] - 1) * 2;
                        }
                    }
                    else {
                        ans += (hash_map[a] - 1) * 2;
                    }
                }
            }
        }
        return ans;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}