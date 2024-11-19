#include <iostream>
#include <string>
#include <map>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;
	string s;
	cin >> s;

	string ret;
	map<char, int> hash_map;
	for (auto& x : s) {
		if (x == '1' || x == '4' || x == '6' || x == '8' || x == '9') {
			cout << 1 << "\n";
			cout << x << "\n";
			return;
		}
		else {
			if (x == '2') {
				if (hash_map.count('2')) {
					ret = "22";
				}
				else if (hash_map.count('3')) {
					ret = "32";
				}
				else if (hash_map.count('5')) {
					ret = "52";
				}
				else if (hash_map.count('7')) {
					ret = "72";
				}
				else hash_map['2'] = 1;
			}
			else if (x == '3') {
				if (hash_map.count('3')) {
					ret = "33";
				}
				else hash_map['3'] = 1;
			}
			else if (x == '5') {
				if (hash_map.count('2')) {
					ret = "25";
				}
				else if (hash_map.count('3')) {
					ret = "35";
				}
				else if (hash_map.count('5')) {
					ret = "55";
				}
				else if (hash_map.count('7')) {
					ret = "75";
				}
				else hash_map['5'] = 1;
			}
			else {
				if (hash_map.count('2')) {
					ret = "27";
				}
				else if (hash_map.count('5')) {
					ret = "57";
				}
				else if (hash_map.count('7')) {
					ret = "77";
				}
				else hash_map['7'] = 1;
			}
		}
	}
	cout << 2 << "\n";
	cout << ret << "\n";
}
int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}