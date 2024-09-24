#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
	int maxOperations(vector<int>& nums, int k) {
		map<int, int> hash_map;
		for (auto& x : nums) {
			hash_map[x]++;
		}

		int ret = 0;
		for (auto& x : nums) {
			if (x != k - x && hash_map[x] && hash_map[k - x]) {
				++ret;
				hash_map[x]--;
				hash_map[k - x]--;
			}
			else if (x == k - x && hash_map[x] >= 2) {
				++ret;
				hash_map[x] -= 2;
			}
		}
		return ret;
	}
};

int main() {

	return 0;
}