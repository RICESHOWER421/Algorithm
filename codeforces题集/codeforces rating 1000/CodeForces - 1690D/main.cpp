#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void Test() {
	int n = 0, k = 0;
	cin >> n >> k;

	string s;
	cin >> s;
	int left = 0, right = 0;
	int ans = INT_MAX, num = 0;
	while (right < n) {
		if (right - left < k) {
			if (s[right] == 'W') ++num;
			++right;
		}
		else {
			ans = min(ans, num);
			if (s[left] == 'W') --num;
			++left;
			if (s[right] == 'W') ++num;
			++right;
		}
	}
	cout << min(ans, num) << endl;
}
int main(){
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}