#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;

	vector<int> nums(5);
	for (int i = 0; i < n; i++) {
		int num = 0;
		cin >> num;
		nums[num % 5]++;
	}

	int ans = nums[4];
	if (nums[1] <= nums[3]) ans += nums[3] + nums[2] / 2 + nums[2] % 2;	//���1������С�ڵ���3����������ô1�Ⱥ�3ƴ���������3һ��һ����2������һ�������������2����һ��
	else {
		ans += nums[3];
		nums[1] -= nums[3];
		while (nums[1] && nums[2]) {
			nums[1] -= (nums[1] >= 2 ? 2 : 1);
			nums[2]--;
			++ans;
		}

		if (nums[1]) ans += nums[1] / 4 + (nums[1] % 4 != 0);
		else if (nums[2]) ans += nums[2] / 2 + nums[2] % 2;
	}
	cout << ans << "\n";
}

int main() {
	Test();
	return 0;
}