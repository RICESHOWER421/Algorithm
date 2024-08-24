#include <iostream>
#include <vector>
#include <string>
using namespace std;

int findPermutationDifference(string s, string t) {
    vector<int> hash_map1(26), hash_map2(26);
    for (int i = 0; i < s.size(); i++) {
        hash_map1[s[i] - 'a'] = i;
        hash_map2[t[i] - 'a'] = i;
    }

    int ans = 0;
    for (int i = 0; i < 26; i++) {
        ans += abs(hash_map1[i] - hash_map2[i]);
    }
    return ans;
}

int main() {

	return 0;
}