#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> nums;
        for (int i = 0; i < n; i++) {
            nums.push_back({position[i], speed[i]});
        }
        sort(nums.begin(), nums.end());

        vector<double> st;
        for (int i = n - 1; i >= 0; i--) {
            double time = (double)(target - nums[i].first) / (double)nums[i].second;
            if (st.empty() || time > st.back()) st.push_back(time);
        }
        return (int)st.size();
    }
};
int main() {

	return 0;
}