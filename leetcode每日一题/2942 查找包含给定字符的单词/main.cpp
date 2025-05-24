#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for (int i = 0; i < words.size(); i++) {
            for (auto& y : words[i]) {
                if (y == x) {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};

int main() {

	return 0;
}