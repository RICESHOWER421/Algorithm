#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
typedef long long ll;
using namespace std;

void Test() {
    ll n = 0;
    cin >> n;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    ll mx = 0;
    vector<ll> dp(n);
    for (int i = n - 1; i >= 0; i--) {
        if (i + nums[i] >= n) {
            dp[i] = nums[i];
        }
        else {
            dp[i] = nums[i] + dp[i + nums[i]];
        }
        mx = max(dp[i], mx);
    }
    cout << mx << "\n";
}

int main() {
    int test = 0;
    cin >> test;
    while (test--) {
        Test();
    } 
    return 0;
}