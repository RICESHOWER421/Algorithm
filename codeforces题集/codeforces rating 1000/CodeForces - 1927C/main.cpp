#include <iostream>
#include <vector>
using namespace std;

void Test() {
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	
	vector<int> num_1(k + 1);
	vector<int> num_2(k + 1);
	for (int i = 0; i < n; i++) {
		int num = 0;
		cin >> num;
		if (num <= k) num_1[num] = 1;
	}

	for (int i = 0; i < m; i++) {
		int num = 0;
		cin >> num;
		if (num <= k) num_2[num] = 1;
	}

	int ret_1 = 0, ret_2 = 0, sum = 0;
	for (int i = 1; i <= k; i++) {
		if (num_1[i] && !num_2[i]) {
			if (ret_1 < k / 2) ++ret_1;
		} 
		else if (!num_1[i] && num_2[i]) {
			if (ret_2 < k / 2) ++ret_2;
		} 
		else if(num_1[i] && num_2[i]) ++sum;
	}

	if (ret_1 + ret_2 + sum >= k) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}