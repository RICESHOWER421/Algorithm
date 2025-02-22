#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int similarPairs(vector<string>& words) {
        int ans = 0;
        map<vector<bool>, int> hash_map;
        for (auto& x : words) {
            vector<bool> a(26);
            for (auto& y : x) {
                a[y - 'a'] = true;
            }
            ans += hash_map[a];
            hash_map[a]++;
        }
        return ans;
    }
};

int main() {

	return 0;
}