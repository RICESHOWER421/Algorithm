#include <bits/stdc++.h>
using namespace std;

//¹þÏ£Ð´·¨
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string, bool> hash_map;
        for (auto& x : arr1) {
            string tmp = to_string(x);
            string str;
            for (auto& x : tmp) {
                str += x;
                hash_map[str] = true;
            }
        }

        int ans = 0;
        for (auto& x : arr2) {
            string tmp = to_string(x);
            string str;
            for (auto& x : tmp) {
                str += x;
                if (hash_map.find(str) != hash_map.end()) ans = max(ans, (int)str.size());
            }
        }
        return ans;
    }
};

//×ÖµäÊ÷Ð´·¨ Trie
struct Node {
    Node* son[10];  //´æ´¢0-9
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Node* root = new Node();

        auto insert = [&](string str)->void {
            Node* cur = root;
            for (auto x : str) {
                x -= '0';
                if (cur->son[x] == nullptr) {
                    cur->son[x] = new Node();
                }
                cur = cur->son[x];
            }
        };

        auto find = [&](string str)->int {
            Node* cur = root;
            int sum = 0;
            for (auto& x : str) {
                x -= '0';
                if (cur->son[x] == nullptr) break;
                ++sum;
                cur = cur->son[x];
            }
            return sum;
        };

        for (auto& x : arr1) {
            insert(to_string(x));
        }
        int ans = 0;
        for (auto& x : arr2) {
            ans = max(ans, find(to_string(x)));
        }
        return ans;
    }
};

int main() {

	return 0;
}