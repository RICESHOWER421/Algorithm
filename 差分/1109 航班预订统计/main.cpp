#include <iostream>
#include <vector>
using namespace std;

vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
	vector<int> diff(n);
	for (int i = 0; i < bookings.size(); i++) {
		int left = bookings[i][0] - 1, right = bookings[i][1] - 1, x = bookings[i][2];
		diff[left] += x;
		if (right + 1 < n) {
			diff[right + 1] -= x;
		}
	}

	for (int i = 1; i < n; i++) {
		diff[i] += diff[i - 1];
	}
	return diff;
}

int main() {

	return 0;
}