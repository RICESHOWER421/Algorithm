#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for (auto& x : nums) {
            if (x < k) {
                pq.push(x);
            }
        }

        int ans = 0;
        while (pq.size() >= 2) {
            ll ret1 = pq.top();
            pq.pop();
            ll ret2 = pq.top();
            pq.pop();
            ll tmp = ret1 * 2 + ret2;
            ++ans;
            if (tmp < k) {
                pq.push(tmp);
            }
        }

        return (int)pq.size() + ans;
    }
};

int main() {

	return 0;
}