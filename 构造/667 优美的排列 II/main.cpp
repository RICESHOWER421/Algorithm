#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;

        int left = 1, right = n;
        bool ok = true;
        while (k--) {
            if (ok) {
                ans.push_back(left);
                ++left;
                ok = false;
            }
            else {
                ans.push_back(right);
                --right;
                ok = true;
            }
        }

        if (ok) {
            for (int i = right; i >= left; i--) {
                ans.push_back(i);
            }
        }
        else {
            for (int i = left; i <= right; i++) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main() {

	return 0;
}