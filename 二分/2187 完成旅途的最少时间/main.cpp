#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long max_num = 0;
        for (int i = 0; i < (int)time.size(); i++) {
            max_num = max((long long)time[i] * totalTrips, max_num);
        }

        long long left = 1, right = max_num;
        while (left < right) {
            long long mid = (left + right) / 2;
            long long sum = 0;
            for (int i = 0; i < (int)time.size(); i++){
                sum += (mid / time[i]);
            }

            if (sum < totalTrips) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};

int main() {
    vector<int> nums = { 1,2,3 };
    int totalTrips = 5;
    cout << Solution().minimumTime(nums, totalTrips) << endl;
	return 0;
}