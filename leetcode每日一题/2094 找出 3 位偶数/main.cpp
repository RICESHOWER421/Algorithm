#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<bool> hash_map(1000);
        int n = digits.size();
        vector<int> ans;
        auto push = [&](int val)->void {
            if (val >= 100 && val <= 999 && !hash_map[val]) {
                ans.push_back(val);
                hash_map[val] = true;
            }
        };
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    int n1 = 0, n2 = 0;
                    if (digits[i] % 2 == 0) {
                        n1 = digits[j] * 100 + digits[k] * 10 + digits[i];
                        n2 = digits[k] * 100 + digits[j] * 10 + digits[i];
                        push(n1), push(n2);
                    }
                    if (digits[j] % 2 == 0) {
                        n1 = digits[k] * 100 + digits[i] * 10 + digits[j];
                        n2 = digits[i] * 100 + digits[k] * 10 + digits[j];
                        push(n1), push(n2);
                    }
                    if (digits[k] % 2 == 0) {
                        n1 = digits[i] * 100 + digits[j] * 10 + digits[k];
                        n2 = digits[j] * 100 + digits[i] * 10 + digits[k];
                        push(n1), push(n2);
                    }
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {

	return 0;
}