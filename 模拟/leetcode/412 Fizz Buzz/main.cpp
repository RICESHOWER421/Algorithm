#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> fizzBuzz(int n) {
	vector<string> arr(n);
	for (int i = 1; i <= n; i++) {
		if (!(i % 3) && i % 5) arr[i - 1] = "Fizz";
		else if (i % 3 && !(i % 5)) arr[i - 1] = "Buzz";
		else if (!(i % 3) && !(i % 5)) arr[i - 1] = "FizzBuzz";
		else arr[i - 1] = to_string(i);
	}
	return arr;
}

int main() {
	int n = 5;
	vector<string> arr = fizzBuzz(n);
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}