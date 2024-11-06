#include <iostream>
#include <map>
#include <string>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;
	string s;
	cin >> s;
	
	if (s.size() < 4) {
		cout << "NO" << "\n";
	}
	else {
		map<string, int> hash_map;
		int begin = 0;
		string ret;
		ret += s[0];
		ret += s[1];
		hash_map[ret] = 1;
		for (int i = 3; i < s.size(); i++) {
			string temp;
			temp += s[i - 1];
			temp += s[i];
			if (hash_map.count(temp)) {
				cout << "YES" << "\n";
				return;
			}
			++begin;
			ret[0] = s[begin];
			ret[1] = s[begin + 1];
			hash_map[ret] = 1;
		}
		cout << "NO" << "\n";
	}
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}