#include <iostream>
#include <vector>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;
	if (n == 0) cout << 1 << endl;	//һ��Ҫע�⿴��Ŀ�����ͺ�����
	else {
		vector<int> nums = { 8,4,2,6 };
		int pos = (n - 1) % 4;
		cout << nums[pos] << endl;
	}
}

int main() {
	Test();
	return 0;
}