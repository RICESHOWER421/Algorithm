#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(), ret = 1;
        vector<int> ans;
        for (int i = n - 1; i >= 0; i--) {
            int num = (digits[i] + ret) % 10;
            ans.push_back(num);
            if(num) ret = 0;
        }
        if (ret) ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {

	return 0;
}