#include <iostream>
#include <string>
using namespace std;

void Test() {
	string s;
	cin >> s;

	int ans = 0;
	while (s.size() > 1) {
		int sum = 0;
		for (auto& x : s) sum += (x - '0');
		s = to_string(sum);
		++ans;
	}
	cout << ans << "\n";
}

int main() {
	Test();
	return 0;
}