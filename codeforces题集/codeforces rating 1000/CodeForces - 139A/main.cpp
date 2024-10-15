#include <iostream>
#include <vector>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;
	vector<int> nums(7);
	for (int i = 0; i < 7; i++) cin >> nums[i];

	int index = 0;
	while (1) {
		if (n > nums[index]) {
			n -= nums[index];
			index = (index + 1) % 7;
		}
		else break;
	}
	cout << index + 1 << endl;
}

int main() {
	Test();
	return 0;
}