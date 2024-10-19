#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
typedef long long ll;
using namespace std;

void Test() {
    int n = 0;
    cin >> n;
    vector<ll> nums;
    ll mn = INT_MAX;
    while (n--) {
        int m = 0;
        cin >> m;
        ll mn_1 = 0, mn_2 = 0;
        while (m--) {
            ll num = 0;
            cin >> num;
            mn = min(mn, num);
            if (mn_1 == 0) {
                mn_1 = num;
            }
            else {
                if (num < mn_1) {
                    mn_2 = mn_1;
                    mn_1 = num;
                }
                else {
                    if (mn_2 == 0) {
                        mn_2 = num;
                    }
                    else {
                        if (num < mn_2) {
                            mn_2 = num;
                        }
                    }
                }
            }
        }
        nums.push_back(mn_2);
    }

    ll index = 0, min_num = nums[0];
    for (int i = 0; i < (int)nums.size(); i++) {
        if (nums[i] < min_num) {
            index = i;
            min_num = nums[i];
        }
    }

    ll ans = 0;
    for (int i = 0; i < (int)nums.size(); i++) {
        if (i != index) {
            ans += nums[i];
        }
    }
    cout << ans + mn << "\n";
}

int main()
{
    int test = 0;
    cin >> test;
    while (test--) {
        Test();
    }
    return 0;
}