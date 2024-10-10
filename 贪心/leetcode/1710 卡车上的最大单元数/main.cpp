#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
		sort(boxTypes.begin(), boxTypes.end(), [&](const vector<int>& a, const vector<int>& b) {
			return a[1] > b[1];
		});

		int ans = 0, ret = 0;
		for (auto& x : boxTypes) {
			ret += x[0];
			ans += (x[0] * x[1]);
			if (ret >= truckSize) {
				ans -= ((ret - truckSize) * x[1]);
				break;
			}
		}
		return ans;
	}
};

int main() {

	return 0;
}