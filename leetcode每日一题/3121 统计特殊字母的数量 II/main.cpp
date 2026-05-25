#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size(), ans = 0;
        vector<pair<int, int>> h(26, { -1, -1 });
        for (int i = 0; i < n; i++) {
            if (word[i] >= 'a' && word[i] <= 'z') h[word[i] - 'a'].first = i;
            if (word[i] >= 'A' && word[i] <= 'Z') {
                if (h[word[i] - 'A'].second == -1) h[word[i] - 'A'].second = i;
            }
        }
        for (int i = 0; i < 26; i++) ans += (h[i].first != -1 && h[i].second != -1 && h[i].first < h[i].second);
        return ans;
    }
};

int main() {

	return 0;
}