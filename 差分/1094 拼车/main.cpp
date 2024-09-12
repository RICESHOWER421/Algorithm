#include <iostream>
#include <vector>
using namespace std;

bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<int> diff(1001);
    for (int i = 0; i < trips.size(); i++) {
        int left = trips[i][1], right = trips[i][2], x = trips[i][0];
        diff[left] += x;
        if (right < diff.size()) {
            diff[right] -= x;
        }
    }

    for (int i = 1; i <= 1000; i++) {
        diff[i] += diff[i - 1];
    }

    for (int i = 0; i <= 1000; i++) {
        if (diff[i] > capacity) return false;
    }
    return true;
}

int main() {

	return 0;
}