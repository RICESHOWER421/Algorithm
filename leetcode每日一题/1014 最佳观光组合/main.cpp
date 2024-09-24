#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
	int maxScoreSightseeingPair(vector<int>& values) {
		int ans = -1, mx = values[0];
		for (int i = 1; i < (int)values.size(); i++) {
			ans = max(ans, mx + values[i] - i);
			mx = max(mx, values[i] + i);
		}
		return ans;
	}
};

int main() {

	return 0;
}