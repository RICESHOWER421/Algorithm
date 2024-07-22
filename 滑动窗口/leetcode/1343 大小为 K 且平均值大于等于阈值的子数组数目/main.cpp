#include <iostream>
#include <vector>
using namespace std;

int numOfSubarrays(vector<int>& arr, int k, int threshold) {
	double sum = 0.0;
	for (int i = 0; i < k; i++)
		sum += arr[i];

	int ret = 0;
	if (sum / k >= threshold) ++ret;
	for (int i = k; i < arr.size(); i++) {
		sum = sum + arr[i] - arr[i - k];
		if (sum / k >= threshold) ++ret;
	}
	return ret;
}
int main() {

	return 0;
}