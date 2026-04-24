#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int cnt = 0, ans = 0;
        for (auto& x : moves) {
            if (x == 'L') ++ans;
            else if (x == 'R') --ans;
            else ++cnt;
        }
        return abs(ans) + cnt;
    }
};

int main() {

	return 0;
}