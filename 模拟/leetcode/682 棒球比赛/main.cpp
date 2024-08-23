#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int calPoints(vector<string>& operations) {
	int i = 0, j = 0;
	vector<int> nums(10001);
	for (int i = 0; i < operations.size(); i++) {
		if (operations[i] == "D") {
			nums[j] = nums[j - 1] * 2;
			++j;
		}
		else if (operations[i] == "+") {
			nums[j] = nums[j - 1] + nums[j - 2];
			++j;
		}
		else if (operations[i] == "C") --j;
		else {
			/*int num = 0, temp = 0, index = 0;
			if (operations[i][0] == '-') index = 1;
			if (index) {
				for (int k = operations[i].size() - 1; k >= 1; k--) num += ((operations[i][k] - '0') * pow(10, temp++));
				nums[j] = -num;
			}
			else {
				for (int k = operations[i].size() - 1; k >= 0; k--) num += ((operations[i][k] - '0') * pow(10, temp++));
				nums[j] = num;
			}*/
			nums[j] = atoi(operations[i].c_str());
			++j;
		}
	}

	int sum = 0;
	for (int k = 0; k < j; k++)
		sum += nums[k];
	return sum;
}

int main() {
	vector<string> operations = { "5","-2","4","C","D","9","+","+" };
	cout << calPoints(operations) << endl;
	return 0;
}