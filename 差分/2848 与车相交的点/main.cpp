#include <iostream>
#include <vector>
using namespace std;

int numberOfPoints(vector<vector<int>>& nums) {
    vector<int> diff(100);
    for (int i = 0; i < nums.size(); i++) {
        int left = nums[i][0], right = nums[i][1];
        diff[left - 1]++;
        if (right < 100) {
            diff[right]--;
        }
    }

    for (int i = 1; i < 100; i++) {
        diff[i] += diff[i - 1];
    }

    int ret = 0;
    for (int i = 0; i < 100; i++) {
        if (diff[i] > 0) ++ret;
    }
    return ret;
}

int main() {
    vector<vector<int>> nums = { {1,5},{3,6},{4,7} };
    cout << numberOfPoints(nums) << endl;
	return 0;
}