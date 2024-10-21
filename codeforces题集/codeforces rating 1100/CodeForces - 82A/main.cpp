#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;

	vector<string> names = {"Sheldon" ,  "Leonard", "Penny","Rajesh" ,"Howard"};
	int begin = 0;
	int sum = 0;
	while (sum + 5 * pow(2, begin) < n) {
		sum += 5 * pow(2, begin);
		++begin;
	}
	cout << names[(n - sum - 1) / (int)pow(2, begin)] << "\n";
}

int main() {
	Test();
	return 0;
}