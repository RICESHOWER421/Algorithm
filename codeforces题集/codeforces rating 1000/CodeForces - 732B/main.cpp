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
    int n = 0, m = 0;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (nums[i] + nums[i - 1] < m) {
            ans += m - (nums[i] + nums[i - 1]);
            nums[i] += m - (nums[i] + nums[i - 1]);
        }
    }
    cout << ans << "\n";
    for (auto& x : nums) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    Test();
	return 0;
}