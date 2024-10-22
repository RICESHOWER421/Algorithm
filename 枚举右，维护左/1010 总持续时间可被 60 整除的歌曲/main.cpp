#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int numPairsDivisibleBy60(vector<int>& time) {
		vector<int> hash_map(61);
		hash_map[time[0] % 60]++;
		int ans = 0;
		for (int i = 1; i < (int)time.size(); i++) {
			if (hash_map[60 - (time[i] % 60)]) {
				ans += hash_map[60 - (time[i] % 60)];
			}
			else if (time[i] % 60 == 0 && hash_map[time[i] % 60]) {
				ans += hash_map[0];
			}
			hash_map[time[i] % 60]++;
		}
		return ans;
	}
};

int main() {

	return 0;
}