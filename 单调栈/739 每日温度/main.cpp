#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> st;
        int n = temperatures.size();
        vector<int> ans(n);
        st.push_back(n - 1);
        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() && temperatures[i] >= temperatures[st.back()]) st.pop_back();
            if(!st.empty()) ans[i] = st.back() - i;
            st.push_back(i);
        }
        return ans;
    }
};

int main() {
    vector<int> t = { 73,74,75,71,69,72,76,73 };
    vector<int> ans = Solution().dailyTemperatures(t);
    for (auto& x : ans) {
        cout << x << "\n";
    }
	return 0;
}