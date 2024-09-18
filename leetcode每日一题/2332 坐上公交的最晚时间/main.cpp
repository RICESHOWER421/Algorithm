#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
	sort(buses.begin(), buses.end());
	sort(passengers.begin(), passengers.end());

	int right = 0, c = 0;
	for (auto& x : buses) {
		for (c = capacity; c && right < (int)passengers.size() && passengers[right] <= x; c--) ++right;
	}
	
	--right;
	int ans = c ? buses.back() : passengers[right];
	while (right >= 0 && ans == passengers[right]) {
		--ans;
		--right;
	}
	return ans;
}

int main() {
	vector<int> buses = { 20,30,10 };
	vector<int> passengers = { 19,13,26,4,25,11,21 };
	int capacity = 2;
	cout << latestTimeCatchTheBus(buses, passengers, capacity) << endl;
	return 0;
}