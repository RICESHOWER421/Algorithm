#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubstringPresent(string s) {
        map<string, int> hash_map;
        for (int i = 0; i < s.size() - 1; i++) {
            hash_map[s.substr(i, 2)]++;
        }
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.size() - 1; i++) {
            if (hash_map.count(s.substr(i, 2))) {
                return true;
            }
        }
        return false;
    }
};

int main() {

	return 0;
}