#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> s;
        for (auto& x : nums) {
            if (x < k) {
                return -1;
            }
            else if (x > k) {
                s.insert(x);
            }
        }
        return s.size();
    }
};

int main() {

	return 0;
}