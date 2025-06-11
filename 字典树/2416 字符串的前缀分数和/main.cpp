#include <bits/stdc++.h>
using namespace std;

struct Node {
	Node* son[26];
	int cnt = 0;
};

class Solution {
public:
	void insert(string str, Node* root) {
		Node* cur = root;
		for (auto& x : str) {
			int pos = x - 'a';
			if (cur->son[pos] == nullptr) cur->son[pos] = new Node();
			cur = cur->son[pos];
			cur->cnt++;
		}
	}

	int find(string str, Node* root) {
		int ans = 0;
		Node* cur = root;
		for (auto& x : str) {
			int pos = x - 'a';
			cur = cur->son[pos];
			ans += cur->cnt;
		}
		return ans;
	}

	vector<int> sumPrefixScores(vector<string>& words) {
		Node* root = new Node();
		int n = words.size();
		vector<int> ans(n);
		for (auto& x : words) {
			insert(x, root);
		}

		for (int i = 0; i < n; i++) {
			ans[i] = find(words[i], root);
		}
		return ans;
	}
};

int main() {

	return 0;
}