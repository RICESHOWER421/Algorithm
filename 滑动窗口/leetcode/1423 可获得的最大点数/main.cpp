#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
	int sum = 0;
	for (int i = 0; i < k; i++) sum += cardPoints[i];

	int ret = sum;
	for (int i = k - 1; i >= 0; i--) {
		sum = sum - cardPoints[i] + cardPoints[i + cardPoints.size() - k];
		ret = max(ret, sum);
	}
	return ret;
}

int main() {
	vector<int> cardPoints = { 1,2,3,4,5,6,1 };
	int k = 3;
	cout << maxScore(cardPoints, k) << endl;
	return 0;
}