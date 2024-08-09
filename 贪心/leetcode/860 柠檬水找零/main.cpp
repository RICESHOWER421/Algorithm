#include <iostream>
#include <vector>
using namespace std;
bool lemonadeChange(vector<int>& bills) {
	int bill_5 = 0, bill_10 = 0;
	for (int i = 0; i < bills.size(); i++) {
		if (bills[i] == 5) ++bill_5;
		else if (bills[i] == 10) {
			if (bill_5 >= 1) {
				--bill_5;
				++bill_10;
			}
			else return false;
		}
		else {
			if (bill_5 >= 1 && bill_10 >= 1) {
				--bill_5;
				--bill_10;
			}
			else if (bill_5 >= 3) {
				bill_5 -= 3;
			}
			else return false;
		}			
	}
	return true;
}

int main() {
	vector<int> nums = { 5,5,10,10,20 };
	cout << lemonadeChange(nums) << endl;
	return 0;
}