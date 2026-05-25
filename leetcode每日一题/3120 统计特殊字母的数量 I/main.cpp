#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans = 0, n = word.size();
        vector<pair<bool, bool>> h(26);
        for (int i = 0; i < n; i++) {
            if (word[i] >= 'a' && word[i] <= 'z') h[word[i] - 'a'].first = true;
            if (word[i] >= 'A' && word[i] <= 'Z') h[word[i] - 'A'].second = true;
        }
        for (int i = 0; i < 26; i++) ans += (h[i].first && h[i].second);
        return ans;
    }
};

int main() {

	return 0;
}