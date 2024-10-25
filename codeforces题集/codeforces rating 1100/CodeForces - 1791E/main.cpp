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

void Test()
{
    int n = 0;
    cin >> n;
    vector<ll> nums(n);
    int ret = 0;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        if (nums[i] < 0) {
            ++ret;
        }
    }

    ll ans = 0;
    ll mn = INT_MAX;
    for (auto& x : nums) {
        ans += abs(x);
        mn = min(mn, abs(x));
    }
    cout << ans - (ret % 2 == 0 ? 0 : 2 * mn) << "\n";
}

int main()
{
    int test = 0;
    cin >> test;
    while (test--)
    {
        Test();
    }
    return 0;
}