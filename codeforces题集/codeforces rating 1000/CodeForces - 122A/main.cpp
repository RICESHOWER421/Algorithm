#include <iostream>
#include <vector>
using namespace std;

int main() {
	int num = 0;
	cin >> num;
		
	int index = 0;
	vector<int> nums = { 4,7,44,47,74,77,444,447,474,744,477,747,774,777 };
	for (int i = 0; i < (int)nums.size(); i++) {
		if (num % nums[i] == 0) {
			index = 1;
			break;
		}
	}
	if (index) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}