#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	
	int sum_1 = 0, sum_2 = 0, sum_3 = 0;
	for (int i = 0; i < n; i++) {
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		sum_1 += a;
		sum_2 += b;
		sum_3 += c;
	}

	if (sum_1 == 0 && sum_2 == 0 && sum_3 == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}