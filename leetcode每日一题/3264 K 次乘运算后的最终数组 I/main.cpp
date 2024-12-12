#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<int, vector<int>, greater<int>> pq;
        map<int, priority_queue<int, vector<int>, greater<int>>> hash_map;

        for (int i = 0; i < nums.size(); i++) {
            if (!hash_map.count(nums[i])) pq.push(nums[i]);
            hash_map[nums[i]].push(i);
        }

        while (1) {
            int ret = pq.top();
            while (!hash_map[ret].empty()) {
                nums[hash_map[ret].top()] *= multiplier;
                hash_map[ret * multiplier].push(hash_map[ret].top());
                hash_map[ret].pop();
                --k;
                if (!k) return nums;
            }
            pq.pop();
            pq.push(ret * multiplier);
        }
        return nums;
    }
};

int main() {

	return 0;
}