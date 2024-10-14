#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;
	
	map<string, int> hash_map;
	vector<string> arr;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (!hash_map.count(s)) arr.push_back(s);
		hash_map[s]++;
	}

	int max_num = 0;
	string ans;
	for (auto& x : arr) {
		if (hash_map[x] > max_num) {
			max_num = hash_map[x];
			ans = x;
		}
	}
	cout << ans << endl;
}

int main() {
	Test();
	return 0;
}