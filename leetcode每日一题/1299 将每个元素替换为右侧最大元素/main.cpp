#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n), mx(n);
        mx[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            mx[i] = max(mx[i + 1], arr[i]);
        }

        for (int i = 0; i < n - 1; i++) {
            ans[i] = mx[i + 1];
        }
        ans.back() = -1;
        return ans;
    }
};

int main() {

	return 0;
}