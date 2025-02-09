#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define MAX 0x3f3f3f3f

void Test() {
	int n = 0;
	cin >> n;

	int cnt = 0, cnt1 = MAX, cnt2 = MAX; //cnt1 = 7, cnt2 = 4
	while (n) {
		if (n % 4 == 0) {
			int tmp = n / 4;
			if (tmp + cnt < cnt1 + cnt2) {
				cnt1 = cnt;
				cnt2 = tmp;
			}
		}

		if (n >= 7) {
			cnt++;
			n -= 7;
		}
		else {
			break;
		}
	}

	if (n == 0 && cnt < cnt1 + cnt2) {
		cnt1 = cnt;
		cnt2 = 0;
	}

	if (cnt1 == MAX) {
		cout << -1 << "\n";
	}
	else {
		while (cnt2--) {
			cout << 4;
		}
		while (cnt1--) {
			cout << 7;
		}
		cout << "\n";
	}
}

int main() {
	Test();
	return 0;
}