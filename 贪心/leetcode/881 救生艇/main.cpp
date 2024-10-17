#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int numRescueBoats(vector<int>& people, int limit) {
		int ret = 0;
		sort(people.begin(), people.end());

		int left = 0, right = people.size() - 1;
		while (left < right) {
			if (people[left] + people[right] <= limit) ++left;
			--right;
			++ret;
		}

		return left == right ? ret + 1 : ret;
	}
};

int main() {

	return 0;
}