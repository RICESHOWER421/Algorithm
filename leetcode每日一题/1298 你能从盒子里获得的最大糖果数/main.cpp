#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

class Solution {
public:
	int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
		int ans = 0, n = status.size();
		vector<bool> boxes(n), Keys(n);
		for (auto& x : initialBoxes) {
			boxes[x] = true;
		}

		while (true) {
			bool ok = false;
			for (int i = 0; i < n; i++) {
				if (boxes[i] && (status[i] || Keys[i])) {
					boxes[i] = false;
					ok = true;
					ans += candies[i];
					for (auto& x : containedBoxes[i]) {
						boxes[x] = true;
					}
					for (auto& x : keys[i]) {
						Keys[x] = true;
					}
				}
			}
			if (!ok) break;
		}
		return ans;
	}
};

int main()
{
	
	return 0;
}