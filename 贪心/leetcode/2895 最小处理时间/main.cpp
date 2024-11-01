#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(tasks.begin(), tasks.end());
        sort(processorTime.begin(), processorTime.end());

        int ans = -1;
        int left = 0, right = tasks.size() - 1;
        while (left < processorTime.size()){
            ans = max(ans, processorTime[left] + tasks[right]);
            ++left;
            right -= 4;
        }
        return ans;
    }
};

int main() {

	return 0;
}