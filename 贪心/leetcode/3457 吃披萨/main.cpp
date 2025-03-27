#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    long long maxWeight(vector<int>& pizzas) {
        sort(pizzas.begin(), pizzas.end());
        int n = pizzas.size();
        ll ans = 0, ret = (n / 4) % 2, cur = n - 1;
        if (ret) {
            for (int i = 0; i < n / 8 + 1; i++) {
                ans += pizzas[cur--];
            }
            for (int i = 0; i < n / 8; i++) {
                ans += pizzas[cur - 1];
                cur -= 2;
            }
        }
        else {
            for (int i = 0; i < n / 8; i++) {
                ans += pizzas[cur--];
            }
            for (int i = 0; i < n / 8; i++) {
                ans += pizzas[cur - 1];
                cur -= 2;
            }
        }
        return ans;
    }
};

int main() {

	return 0;
}