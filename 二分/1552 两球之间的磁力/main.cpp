#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size(), l = 0, r = 0;
        sort(position.begin(), position.end());
        r = position.back();
        auto check = [&](int pos)->bool {
            int cnt = 1, tmp = position[0];
            for (int i = 1; i < n; i++) {
                if (position[i] - tmp >= pos) {
                    ++cnt;
                    tmp = position[i];
                }
                if (cnt == m) return true;
            }
            return false;
        };
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};

int main() {

	return 0;
}