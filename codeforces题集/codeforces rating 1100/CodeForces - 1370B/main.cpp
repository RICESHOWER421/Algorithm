#include <iostream>
#include <vector>
using namespace std;
 
void Test() {
	int n = 0;
	cin >> n;
	vector<int> odd, even;
	for (int i = 1; i <= 2 * n; i++) {
		int num = 0;
		cin >> num;
		if (num % 2) odd.push_back(i);
		else even.push_back(i);
	}

	if (odd.size() % 2 && even.size() % 2) {
		for (int i = 0; i < (int)odd.size() - 1; i += 2) {
			cout << odd[i] << " " << odd[i + 1] << "\n";
		}
		for (int i = 0; i < (int)even.size() - 1; i += 2) {
			cout << even[i] << " " << even[i + 1] << "\n";
		}
	}
	else {
		if (odd.empty()) {
			even.pop_back();
			even.pop_back();
		}
		else {
			odd.pop_back();
			odd.pop_back();
		}
		for (int i = 0; i < (int)odd.size(); i += 2) {
			cout << odd[i] << " " << odd[i + 1] << "\n";
		}
		for (int i = 0; i < (int)even.size(); i += 2) {
			cout << even[i] << " " << even[i + 1] << "\n";
		}
	}
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}