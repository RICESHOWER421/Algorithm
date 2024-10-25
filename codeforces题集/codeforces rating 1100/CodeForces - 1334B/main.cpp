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
    int n = 0, k = 0;
    cin >> n >> k;

    vector<ll> better, worse;
    for (int i = 0; i < n; i++) {
        ll num = 0;
        cin >> num;
        if (num >= k) {
            better.push_back(num);
        }
        else {
            worse.push_back(num);
        }
    }

    vector<ll> dp1(better.size() + 1), dp2(worse.size() + 1);
    sort(better.begin(), better.end());
    sort(worse.begin(), worse.end(), greater<ll>());
    for (int i = 1; i < dp1.size(); i++) {
        dp1[i] = dp1[i - 1] + better[i - 1];
    }
    for (int i = 1; i < dp2.size(); i++) {
        dp2[i] = dp2[i - 1] + worse[i - 1];
    }

    int left = 1, right = 1;
    while (left < dp1.size() && right < dp2.size()) {
        double ret = (dp1[left] + dp2[right]) / (double)(left + right);
        if (ret >= k)
        {
            ++right;
        }
        else {
            ++left;
        }
    }
    cout << better.size() + right - 1 << "\n";
}

int main() {
    int test = 0;
    cin >> test;
    while (test--) {
        Test();
    }
    return 0;
}
