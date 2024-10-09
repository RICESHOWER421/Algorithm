#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxIceCream(vector<int>& costs, int coins) {
		sort(costs.begin(), costs.end());

		int ans = 0;
		int sum = 0;
		for (auto& x : costs) {
			if (sum + x <= coins) {
				++ans;
				sum += x;
			}
			else break;
		}
		return ans;
	}
};
int main() {

	return 0;
}