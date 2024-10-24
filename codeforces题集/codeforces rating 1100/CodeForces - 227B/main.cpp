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
    map<ll, pair<int, int>> hash_map;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        hash_map[nums[i]].first = i + 1;
        hash_map[nums[i]].second = n - i;
    }

    ll m = 0;
    cin >> m;
    ll ans_1 = 0, ans_2 = 0;
    for (int i = 0; i < m; i++) {
        ll num = 0;
        cin >> num;
        ans_1 += hash_map[num].first;
        ans_2 += hash_map[num].second;
    }
    cout << ans_1 << " " << ans_2 << "\n";
}

int main()
{
    Test();
    return 0;
}