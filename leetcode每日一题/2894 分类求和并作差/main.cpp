#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int n1 = 0, n2 = 0;
        for (int i = 1; i <= n; i++) {
            if (i % m) n1 += i;
            else n2 += i;
        }
        return n1 - n2;
    }
};

int main() {

	return 0;
}