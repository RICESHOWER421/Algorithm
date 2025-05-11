#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        if (n == 1 || n == 2) return false;
        for (int i = 1; i < n - 1; i++) {
            if (arr[i] % 2 && arr[i - 1] % 2 && arr[i + 1] % 2) {
                return true;
            }
        }
        return false;
    }
};

int main() {

	return 0;
}