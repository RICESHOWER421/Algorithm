#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<int> hash_map;
        for (auto& x : nums) {
            int cur = n - 1, cnt = 0, sum = 0;
            while (cur >= 0) {
                sum += (x[cur--] - '0') * pow(2, cnt++);
            }
            hash_map.insert(sum);
        }

        int ans = 0;
        while (hash_map.find(ans) != hash_map.end()) ++ans;
        string str;
        for (int i = 0; i < n; i++) {
            str += ((ans % 2) + '0');
            ans /= 2;
        }
        reverse(str.begin(), str.end());
        return str;
    }
};

int main() {

	return 0;
}