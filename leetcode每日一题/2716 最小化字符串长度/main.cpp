#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizedStringLength(string s) {
        int cnt = 0;
        vector<bool> hash_map(26);
        for (auto& x : s) {
            hash_map[x - 'a'] = true;
        }

        for (int i = 0; i < 26; i++) {
            cnt += hash_map[i];
        }
        return cnt;
    }
};

int main() {

	return 0;
}