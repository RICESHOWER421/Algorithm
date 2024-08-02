#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <cmath>
using namespace std;

//25 50 75 00(0)
int minimumOperations(string num){
	map<char, stack<int>> hash_map;
	for (int i = 0; i < num.size(); i++)
		hash_map[num[i]].push(i);

	int ret = 0;
	for (int i = num.size() - 1; i >= 0; i--) {
		hash_map[num[i]].pop();
		if (num[i] == '0') {
			if (!hash_map['0'].empty()) {
				if (hash_map['0'].top() > 0) ret = max(ret, hash_map['0'].top() + 2);
				else ret = max(ret, 1);
			}
			if (!hash_map['5'].empty()) ret = max(ret, hash_map['5'].top() + 2);
			if (hash_map['5'].empty() && hash_map['0'].empty()) ret = max(ret, 1);
		}
 		else if (num[i] == '5') {
			if (!hash_map['2'].empty()) ret = max(ret, hash_map['2'].top() + 2);
			if (!hash_map['7'].empty()) ret = max(ret, hash_map['7'].top() + 2);
		}
	}
	return num.size() - ret;
}

int main() {
	string num = "1";
	cout << minimumOperations(num) << endl;
	return 0;
}