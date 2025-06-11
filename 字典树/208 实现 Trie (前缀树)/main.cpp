#include <bits/stdc++.h>
using namespace std;

struct Node {
	Node* son[26];
	bool end = false;
};

class Trie {
public:
	Node* root = new Node();

	int find(string str) {
		Node* cur = root;
		for (auto x : str) {
			x -= 'a';
			if (cur->son[x] == nullptr) {
				return 0;
			}
			cur = cur->son[x];
		}
		return cur->end ? 2 : 1;	//2表示找到了完整子串，1表示只找到了前缀串 
	}

	Trie() {

	}

	void insert(string word) {
		Node* cur = root;
		for (auto x : word) {
			x -= 'a';
			if (cur->son[x] == nullptr) {
				cur->son[x] = new Node();
			}
			cur = cur->son[x];
		}
		cur->end = true;
	}

	bool search(string word) {
		return find(word) == 2;
	}

	bool startsWith(string prefix) {
		return find(prefix);
	}
};

int main() {

	return 0;
}