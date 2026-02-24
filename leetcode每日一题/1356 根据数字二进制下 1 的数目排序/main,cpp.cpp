#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](const int a, const int b) {
            int c1 = 0, c2 = 0, t1 = a, t2 = b;
            while (t1) {
                c1 += (t1 % 2);
                t1 >>= 1;
            }
            while (t2) {
                c2 += (t2 % 2);
                t2 >>= 1;
            }
            return c1 == c2 ? a < b : c1 < c2;
        });
        return arr;
    }
};

int main() {

	return 0;
}