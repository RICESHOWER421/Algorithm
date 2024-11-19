#include <iostream>
#include <vector>
using namespace std;

void Test() {
	int n = 0, v = 0;
	cin >> n >> v;

	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		int k = 0;
		cin >> k;
		bool ok = false;
		while (k--) {
			int num = 0;
			cin >> num;
			if (num < v) ok = true;
		}
		if (ok) ans.push_back(i);
	}

	cout << ans.size() << "\n";
	for (auto& x : ans) {
		cout << x << " ";
	}
	cout << "\n";
}

int main() {
	Test();
	return 0;
}