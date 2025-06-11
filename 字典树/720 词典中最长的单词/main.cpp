#include <bits/stdc++.h>
using namespace std;

struct Node {
	Node* son[26];
};

class Solution {
public:
	bool insert(string str, Node* root) {
		Node* cur = root;
		for (int i = 0; i < str.size(); i++) {
			int pos = str[i] - 'a';
			if (cur->son[pos] != nullptr) cur = cur->son[pos];
			else {
				if (i == str.size() - 1) {
					cur->son[pos] = new Node();
				}
				else return false;
			}
		}
		return true;
	}

	string longestWord(vector<string>& words) {
		Node* root = new Node();
		sort(words.begin(), words.end(), [&](string& a, string& b) {
			return a.size() < b.size();
			});

		string ans = "";
		for (auto& x : words) {
			bool ok = insert(x, root);
			if (ok) {
				if (x.size() > ans.size()) ans = x;
				else if (x.size() == ans.size()) ans = min(ans, x);
			}
		}
		return ans;
	}
};

int main() {

	return 0;
}