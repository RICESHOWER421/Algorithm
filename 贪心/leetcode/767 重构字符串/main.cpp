#include <iostream>
#include <string>
#include <vector>
using namespace std;
string reorganizeString(string s) {
	vector<int> hash_map(26);
	string arr;
	string ret;
	for (int i = 0; i < s.size(); i++) ret += 'a';	//³õÊ¼»¯×Ö·û´®

	pair<char, int> max_time = {0,-1};
	for (int i = 0; i < s.size(); i++) {
		if (!hash_map[s[i] - 'a']) arr += s[i];
		hash_map[s[i] - 'a']++;
		if (hash_map[s[i] - 'a'] > max_time.second) {
			max_time.first = s[i];
			max_time.second = hash_map[s[i] - 'a'];
		}
	}

	if (max_time.second > (s.size() + 1) / 2) return "";
	else {
		int index = 0;
		while (max_time.second) {
			ret[index] = max_time.first;
			index += 2;
			max_time.second -= 1;
			if (index >= s.size()) index = 1;
		}

		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] != max_time.first) {
				while (hash_map[arr[i] - 'a']) {
					ret[index] = arr[i];
					index += 2;
					if (index >= s.size()) index = 1;
					--hash_map[arr[i] - 'a'];
				}
			}
		}
		return ret;
	}
}

int main() {
	string s = "aab";
	cout << reorganizeString(s) << endl;
	return 0;
}