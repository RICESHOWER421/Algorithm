#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int halveArray(vector<int>& nums) {
	priority_queue<double> heap;
	double sum = 0.0;
	int time = 0;
	for (int i = 0; i < nums.size(); i++) {
		heap.push(nums[i]);
		sum += nums[i];
	}

	sum /= 2.0;
	while (sum > 0) {
		double temp = heap.top() / 2.0;
		heap.pop();
		sum -= temp;
		++time;
		heap.push(temp);
	}

	return time;
}

int main() {

	return 0;
}