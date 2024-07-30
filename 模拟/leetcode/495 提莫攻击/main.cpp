#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int findPoisonedDuration(vector<int>& timeSeries, int duration) {
	int n = timeSeries.size();
	int return_num = 0, time = 0;
	if (n == 1) return duration;
	for (int i = 0; i < n - 1; i++) {
		if (timeSeries[i + 1] - timeSeries[i] > duration)
			time += duration;
		else
			time += timeSeries[i + 1] - timeSeries[i];
	}
	time += duration;
	return time;
}

int main() {
	int num = 0;
	cin >> num;
	int duration = 0;
	cin >> duration;
	int* nums = new int[num];
	for (int i = 0; i < num; i++)
		cin >> nums[i];
	vector<int> timeSeries(nums, nums + num);
	cout << findPoisonedDuration(timeSeries, duration) << endl;
	return 0;
}