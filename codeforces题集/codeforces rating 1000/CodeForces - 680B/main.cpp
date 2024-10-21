#include <iostream>
#include <vector>
using namespace std;

void Test() {
	int n = 0, k = 0;
	cin >> n >> k;
	vector<int> nums(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	
	int begin = 1;
	int ans = nums[k];
	while (true) {
		int ret_1 = 1, ret_2 = 1;
		if (k - begin >= 1 && nums[k - begin] == 0) ret_1 = 0;
		else if (k - begin < 1) ret_1 = -1;

		if (k + begin <= n && nums[k + begin] == 0) ret_2 = 0;
		else if (k + begin > n) ret_2 = -1;

		if (ret_1 == 1 && ret_2 == 1) ans += 2;
		else if (ret_1 == -1 && ret_2 == 1 || ret_1 == 1 && ret_2 == -1) ++ans;
		else if (ret_1 == -1 && ret_2 == -1) break;
		++begin;
	}
	cout << ans << "\n";
}
int main() {
	Test();
	return 0;
}