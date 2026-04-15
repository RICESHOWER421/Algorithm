#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        vector<int> idx;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            if (words[i] == target) idx.push_back(i);
        }

        int ans = 101;
        for (auto& x : idx) {
            if (x > startIndex) ans = min(ans, min(x - startIndex, n - x + startIndex));
            else ans = min(ans, min(startIndex - x, n - startIndex + x));
        }
        return ans == 101 ? -1 : ans;
    }
};

int main() {

	return 0;
}