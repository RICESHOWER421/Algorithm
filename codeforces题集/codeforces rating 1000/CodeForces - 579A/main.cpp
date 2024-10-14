#include <iostream>
using namespace std;
typedef long long ll;

//这题是逆向思维
void Test() {
	int n = 0;
	cin >> n;

	int ans = 0;
	while (n) {
		int begin = 1;
		while (begin * 2 <= n) {
			begin *= 2;
		}
		++ans;
		n -= begin;
	}
	cout << ans << endl;
}

int main() {
	Test();
	return 0;
}
