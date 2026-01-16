#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(n), st;
        ans[n - 1] = prices[n - 1];
        st.push_back(n - 1);
        for (int i = n - 2; i >= 0; i--) {
            ans[i] = prices[i];
            while (!st.empty() && prices[i] < prices[st.back()]) st.pop_back();
            if (!st.empty()) ans[i] -= prices[st.back()];
            st.push_back(i);
        }
        return ans;
    }
};

int main() {
    vector<int> p = { 8,4,6,2,3 };
    vector<int> ans = Solution().finalPrices(p);
    for (auto& x : ans) {
        cout << x << " ";
    }
	return 0;
}