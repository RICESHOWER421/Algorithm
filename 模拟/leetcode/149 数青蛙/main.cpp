#include <iostream>
#include <string>
#include <vector>
using namespace std;

int minNumberOfFrogs(string croakOfFrogs) {
	vector<int> hash(5);
	int temp = 0;
	for (int i = 0; i < croakOfFrogs.size(); i++) {
		if (croakOfFrogs[i] == 'c') {
			if (hash[4]) --hash[4];
			++hash[0];
		}
		else if (croakOfFrogs[i] == 'r') {
			if (hash[0]) {
				--hash[0];
				++hash[1];
			}
			else {
				temp = 1;
				break;
			}
		}
		else if (croakOfFrogs[i] == 'o') {
			if (hash[1]) {
				--hash[1];
				++hash[2];
			}
			else {
				temp = 1;
				break;
			}
		}
		else if (croakOfFrogs[i] == 'a') {
			if (hash[2]) {
				--hash[2];
				++hash[3];
			}
			else {
				temp = 1;
				break;
			}
		}
		else{
			if (hash[3]) {
				--hash[3];
				++hash[4];
			}
			else {
				temp = 1;
				break;
			}
		}
	}
	if (temp == 1 || hash[0] + hash[1] + hash[2] + hash[3]) return -1;
	else return hash[4];
}

int main() {
	string str = "";
	cout << minNumberOfFrogs(str) << endl;
	return 0;
}