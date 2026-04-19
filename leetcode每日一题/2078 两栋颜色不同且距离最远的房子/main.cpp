#include <bits/stdc++.h>
using namespace std;

//O(N^2)±©Á¦Ã¶¾Ù
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (colors[i] != colors[j]) ans = max(ans, j - i);
            }
        }
        return ans;
    }
};

//O(N)Ð´·¨
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size(), ans = 0;
        if (colors[0] != colors[n - 1]) return n - 1;
        for (int i = 1; i < n - 1; i++) {
            if (colors[i] != colors[0]) ans = max(ans, i);
            if (colors[i] != colors[n - 1]) ans = max(ans, n - 1 - i);
        }
        return ans;
    }
};

int main() {

	return 0;
}