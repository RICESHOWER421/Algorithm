#include <iostream>
#include <vector>
using namespace std;

//-1 -2 -4 3 4 -4 2 1
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	int n = gas.size();
	for (int i = 0; i < n; i++) {
		int step = 0;
		int sum = 0;
		for (; step < n; step++) {
			int index = (i + step) % n;
			sum += (gas[index] - cost[index]);
			if (sum < 0) break;
		}
		if (sum >= 0) return i;
		i = i + step;
	}
	return -1;
}

int main() {

	return 0;
}