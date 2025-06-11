#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct Node {
	Node* son[26];
	bool end = false;
};

class Solution {
public:
	void insert(string str, Node* root) {
		Node* cur = root;
		for (auto x : str) {
			x -= 'a';
			if (cur->son[x] == nullptr) cur->son[x] = new Node();
			cur = cur->son[x];
		}
		cur->end = true;
	}

	string find(string str, Node* root) {
		Node* cur = root;
		string ret;
		for (auto x : str) {
			if (cur->end) return ret;
			int pos = x - 'a';
			if (cur->son[pos] == nullptr) return "";
			ret += x;
			cur = cur->son[pos];
		}
		return ret;
	}

	string replaceWords(vector<string>& dictionary, string sentence) {
		Node* root = new Node();
		for (auto& x : dictionary) {
			insert(x, root);
		}

		sentence += ' ';
		vector<string> ans;
		string ret;
		for (int i = 0; i < sentence.size(); i++) {
			if (sentence[i] != ' ') ret += sentence[i];
			else {
				string s = find(ret, root);
				if (s.empty()) ans.push_back(ret);
				else ans.push_back(s);
				ret.clear();
			}
		}

		string tmp;
		for (int i = 0; i < ans.size(); i++) {
			tmp += ans[i];
			if (i != ans.size() - 1) tmp += " ";
		}
		return tmp;
	}
};


int main() {
	vector<string> dic = { "cat","bat","rat" };
	string ret = "the cattle was rattled by the battery";
	cout << Solution().replaceWords(dic, ret) << "\n";
	return 0;
}