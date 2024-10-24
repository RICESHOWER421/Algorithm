#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
typedef long long ll;
using namespace std;

void Test() {
    int n = 0;
    cin >> n;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<ll> dp1(n + 1);
    for (int i = 1; i <= n; i++) dp1[i] = dp1[i - 1] + nums[i - 1];
    sort(nums.begin(), nums.end());
    vector<ll> dp2(n + 1);
    for (int i = 1; i <= n; i++) dp2[i] = dp2[i - 1] + nums[i - 1];

    int m = 0;
    cin >> m;
    while (m--) {
        int pos = 0, l = 0, r = 0;
        cin >> pos >> l >> r;
        if (pos == 1) {
            cout << dp1[r] - dp1[l - 1] << "\n";
        }
        else {
            cout << dp2[r] - dp2[l - 1] << "\n";
        }
    }
}

int main()
{
    Test();
    return 0;
}