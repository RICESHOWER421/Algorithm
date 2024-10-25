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
    vector<int> nums(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());
    cout << nums[n] - nums[n - 1] << "\n";
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