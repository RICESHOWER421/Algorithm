#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int ans = 0;
        vector<int> arr;
        for (int i = 0; i < (int)capacity.size(); i++) {
            if (capacity[i] - rocks[i]) arr.push_back(capacity[i] - rocks[i]);
            else ++ans;
        }

        sort(arr.begin(), arr.end());
        int index = 0;
        while (additionalRocks && index < (int)arr.size()) {
            if (additionalRocks >= arr[index]) {
                additionalRocks -= arr[index];
                ++ans;
                ++index;
            }
            else break;
        }
        return ans;
    }
};

int main() {

	return 0;
}