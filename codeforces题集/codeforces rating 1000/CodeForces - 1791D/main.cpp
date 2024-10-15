#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <set>
using namespace std;


//这道题目需要依次对每种情况查找取最大值，而不是简单的找第一个没有重复字符的字符串就能解决问题的，这道题目写着还是有收获的
void Test() {
	int n = 0;
	cin >> n;
	string s;
	cin >> s;

	map<char, int> hash_map;
	vector<int> arr(n + 1);
	for (int i = n - 1; i >= 0; i--) {
		if (!hash_map.count(s[i])) hash_map[s[i]] = 1;
		arr[i] = hash_map.size();
	}

	hash_map.clear();
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (!hash_map.count(s[i])) hash_map[s[i]] = 1;
		ans = max(ans, (int)hash_map.size() + arr[i + 1]);
	}
	cout << ans << endl;
}

//错误思路
//void Test() {
//	int n = 0;
//	cin >> n;
//	string s;
//	cin >> s;
//
//	vector<int> hash_map1(26);
//	vector<int> hash_map2(26);
//	int ret_1 = 0, ret_2 = 0;
//	int index = -1;
//	for (int i = 0; i < n; i++) {
//		if (hash_map1[s[i] - 'a'] == 0) ++ret_1;
//		else {
//			index = i;
//			break;
//		}
//		hash_map1[s[i] - 'a']++;
//	}
//
//	if (index != -1) {
//		for (int i = index; i < n; i++) {
//			if (hash_map2[s[i] - 'a'] == 0) ++ret_2;
//			hash_map2[s[i] - 'a']++;
//		}
//	}
//	cout << ret_1 + ret_2 << endl;
//}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}