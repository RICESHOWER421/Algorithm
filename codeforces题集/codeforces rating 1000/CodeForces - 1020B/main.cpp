#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;

	vector<int> nums(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}

	vector<int> count(n + 1);
	for (int i = 1; i <= n; i++) {
		fill(count.begin(), count.end(), 0);
		count[i]++;
		int cur = i;
		while (count[cur] < 2) {
			cur = nums[cur];
			count[cur]++;
		}
		cout << cur << " ";
	}
	cout << "\n";
}

int main() {
	Test();
	return 0;
}