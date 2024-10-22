#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Test() {
	string s;
	cin >> s;

	vector<pair<char, int>> a, b;
	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] == 'b') {
			if (!a.empty()) a.pop_back();
		}
		else if (s[i] == 'B') {
			if (!b.empty()) b.pop_back();
		}
		else {
			if (s[i] >= 'a' && s[i] <= 'z') a.push_back({ s[i], i });
			else b.push_back({ s[i], i });
		}
	}

	int left = 0, right = 0;
	while (left < a.size() && right < b.size()) {
		if (a[left].second < b[right].second) {
			cout << a[left].first;
			++left;
		}
		else {
			cout << b[right].first;
			++right;
		}
	}

	while (left < a.size()) {
		cout << a[left].first;
		++left;
	}

	while (right < b.size()) {
		cout << b[right].first;
		++right;
	}
	cout << "\n";
}
int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}