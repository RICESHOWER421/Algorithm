#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countLargestGroup(int n) {
        map<int, int> hash_map;
        for (int i = 1; i <= n; i++) {
            int tmp = i, sum = 0;
            while (tmp) {
                sum += (tmp % 10);
                tmp /= 10;
            }
            hash_map[sum]++;
        }

        int mx = -1, cnt = 0;
        auto it = hash_map.begin();
        while(it != hash_map.end()) {
            if (it->second > mx) {
                mx = it->second;
                cnt = 1;
            }
            else if (it->second == mx) {
                ++cnt;
            }
            ++it;
        }
        return cnt;
    }
};

int main() {

	return 0;
}