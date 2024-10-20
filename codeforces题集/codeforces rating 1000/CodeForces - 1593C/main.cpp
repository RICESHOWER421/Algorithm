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
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> nums(k);
    for (int i = 0; i < k; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end(), greater<int>());
    ll ret = 0, cur = 0;
    while (nums[cur] > ret && cur < k) {
        ret += n - nums[cur];
        ++cur;
    }
    cout << cur << "\n";
}

int main() {
    int test = 0;
    cin >> test;
 
    while (test--) {
        Test();
    }
    return 0;
}