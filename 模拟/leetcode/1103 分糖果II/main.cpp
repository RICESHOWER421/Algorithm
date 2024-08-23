#include <iostream>
#include <vector>
using namespace std;

vector<int> distributeCandies(int candies, int num_people) {
	vector<int> nums(num_people);
	int index = 1;
	int temp = 0;
	while (candies) {
		if (temp == num_people) temp = 0;
		if (index > candies) {
			nums[temp] += candies;
			candies = 0;
		}
		else {
			nums[temp] += index;
			candies -= index;
		}
		++index;
		++temp;

	}
	return nums;
}

int main() {
	int candies = 10, num_people = 3;
	vector<int> nums = distributeCandies(candies, num_people);
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
	return 0;
}