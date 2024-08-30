#include <iostream>
#include <vector>
using namespace std;

//1 2 3 4 5 6
//3 2 3 2 2 1
long long sumDigitDifferences(vector<int>& nums) {
	long long ans = 0;
	while (nums[0] > 0) {
		vector<int> arr(10);
		for (int i = 0; i < nums.size(); i++) {
			arr[nums[i] % 10]++;
			nums[i] /= 10;
		}

		for (int i = 0; i < 10; i++) {
			ans += (nums.size() - arr[i]) * arr[i];
		}
	}
	return ans / 2;
}

int main() {

	return 0;
}