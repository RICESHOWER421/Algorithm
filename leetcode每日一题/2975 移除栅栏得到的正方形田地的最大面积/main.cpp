#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

//±©Á¦Ã¶¾Ù
class Solution {
public:
    using ll = long long;
    const ll MOD = 1e9 + 7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        if (m == n) return (ll)(m - 1) * (n - 1) % MOD;
        unordered_set<int> st;
        hFences.push_back(1);
        hFences.push_back(m);
        int sz1 = hFences.size();
        for (int i = 0; i < sz1; i++) {
            for (int j = i + 1; j < sz1; j++) {
                st.insert(abs(hFences[j] - hFences[i]));
            }
        }

        vFences.push_back(1);
        vFences.push_back(n);
        ll ans = -1;
        int sz2 = vFences.size();
        for (int i = 0; i < sz2; i++) {
            for (int j = i + 1; j < sz2; j++) {
                ll ret = abs(vFences[j] - vFences[i]);
                if (st.find(ret) != st.end()) ans = max(ans, ret);
            }
        }
        return ans == -1 ? -1 : ans * ans % MOD;
    }
};

int main() {
    int m = 4, n = 3;
    vector<int> h = { 2,3 }, v = { 2 };
    cout << Solution().maximizeSquareArea(m, n, h, v) << "\n";
	return 0;
}