#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        map<string, bool> hash_map;
        string ret;
        for (auto& x : s) {
            ret += x;
            hash_map[ret] = true;
        }

        int cnt = 0;
        for (auto& x : words) {
            cnt += hash_map[x];
        }
        return cnt;
    }
};

int main() {

	return 0;
}