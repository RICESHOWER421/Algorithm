#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        vector<int> hash_map(26);
        string arr;
        for (auto& x : s) { 
            if (hash_map[x - 'a'] == 0) arr += x;
            hash_map[x - 'a']++;
        }

        sort(arr.begin(), arr.end(), [&](const char a, const char b) {
            return hash_map[a - 'a'] > hash_map[b - 'a'];
        });

        int ans = 0;
        for (int i = 1; i < (int)arr.size(); i++) {
            if (hash_map[arr[i - 1] - 'a'] == 0) {
                ans += hash_map[arr[i] - 'a'];
                hash_map[arr[i] - 'a'] = 0;
            }
            else {
                ans += (hash_map[arr[i] - 'a'] - min(hash_map[arr[i - 1] - 'a'] - 1, hash_map[arr[i] - 'a']));
                hash_map[arr[i] - 'a'] = min(hash_map[arr[i - 1] - 'a'] - 1, hash_map[arr[i] - 'a']);
            }
        }
        return ans;
    }
};

int main() {
    string s = "nhgffkjjlnglnegfmcmjamdgjdf";
    cout << Solution().minDeletions(s) << endl;
	return 0;
}