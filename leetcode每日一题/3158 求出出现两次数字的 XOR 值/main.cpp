#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        vector<int> arr(51);
        int ans = 0;
        for (auto& x : nums) {
            arr[x]++;
            if (arr[x] == 2) ans ^= x;
        }
        return ans;
    }
};

int main() {

	return 0;
}