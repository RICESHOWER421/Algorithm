#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string destCity(vector<vector<string>>& paths) {
		map<string, string> hash_map;
		for (int i = 0; i < (int)paths.size(); i++) {
			hash_map[paths[i][0]] = paths[i][1];
		}

		string ans = paths[0][0];
		while (hash_map.count(ans)) {
			ans = hash_map[ans];
		}
		return ans;
	}
};

int main() {

	return 0;
}