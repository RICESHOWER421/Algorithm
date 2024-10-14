#include <iostream>
#include <vector>
using namespace std;

//这题模拟细节也要处理好，wa了两次了
void Test() {
	int n = 0, k = 0;
	cin >> n >> k;
	vector<int> nums(n);
	for (int i = 1; i <= n - 1; i++) {
		cin >> nums[i];
	}

	int begin = 1;
	while (begin <= n) {
		if (begin == k) {
			cout << "YES" << endl;
			return;
 		}
		if (begin == n) break;
		begin += nums[begin];
	}
	cout << "NO" << endl;
}

int main() {
	Test();
	return 0;
}