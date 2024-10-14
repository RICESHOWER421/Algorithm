#include <iostream>
#include <string>
#include <map>
using namespace std;

void Test() {
	int n = 0, m = 0;
	cin >> n >> m;
	map<string, string> hash_map;
	while (m--) {
		string a, b;
		cin >> a >> b;
		if (b.size() < a.size()) {
			hash_map[a] = b;
			hash_map[b] = b;
		}
		else {
			hash_map[a] = a;
			hash_map[b] = a;
		}
	}

	string ret;
	while (n--) {
		string s;
		cin >> s;
		ret = ret + hash_map[s] + " ";
	}
	cout << ret << endl;
}

int main() {
	Test();
	return 0;
}