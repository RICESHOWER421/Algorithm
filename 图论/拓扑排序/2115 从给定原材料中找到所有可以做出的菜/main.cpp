#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
		unordered_map<string, bool> hash_map;
		for (auto& x : supplies) {
			hash_map[x] = true;
		}

		while (true) {
			bool ok1 = false;
			for (int i = 0; i < recipes.size(); i++) {
				if (!hash_map.count(recipes[i])) {
					bool ok2 = true;
					for (auto& x : ingredients[i]) {
						if (!hash_map.count(x)) {
							ok2 = false;
							break;
						}
					}
					if (ok2) {
						ok1 = true;
						hash_map[recipes[i]] = true;
					}
				}
			}
			if (!ok1) {
				break;
			}
		};

		vector<string> ans;
		for (auto& x : recipes) {
			if (hash_map.count(x)) {
				ans.push_back(x);
			}
		}
		return ans;
	}
};

int main() {

	return 0;
}