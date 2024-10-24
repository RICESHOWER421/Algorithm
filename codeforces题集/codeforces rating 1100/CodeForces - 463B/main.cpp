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
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int ret = 0;
    int mn = INT_MAX;
    for (int i = 0; i < n - 1; i++) {
        ret += (nums[i] - nums[i + 1]);
        mn = min(mn, ret);
    }
    cout << nums[0] + (mn < 0 ? -mn : 0) << "\n";
}

int main()
{
    Test();
    return 0;
}