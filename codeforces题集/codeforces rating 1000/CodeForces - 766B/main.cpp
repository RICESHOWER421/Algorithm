#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

void Test() {
	int n = 0;
	cin >> n;

	vector<ll> nums(n);
	bool ok = false;
	for (int i = 0; i < n; i++) cin >> nums[i];
	sort(nums.begin(), nums.end());
	for (int i = 2; i < n; i++) {
		if (nums[i - 2] + nums[i - 1] > nums[i]) {
			ok = true;
			break;
		}
	}
	
	if (ok) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	Test();
	return 0;
}