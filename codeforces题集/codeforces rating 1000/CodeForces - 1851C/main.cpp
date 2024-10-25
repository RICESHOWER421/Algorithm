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
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int num = nums.back();
    int ret = 0;
    int index = -1;
    bool ok = true;
    for (int i = n - 1; i >= 0; i--) {
        if (nums[i] == num) {
            ++ret;
        }

        if (ret == k && ok) {
            index = i;
            ok = false;
        }
    }

    if (ret >= k && nums[0] == num) {
        cout << "YES" << "\n";
        return;
    }
    else if (index == -1) {
        cout << "NO" << "\n";
        return;
    }

    num = nums[0];
    ret = 0;
    for (int i = 0; i < index; i++) {
        if (num == nums[i]) {
            ++ret;
        }
        if (ret == k) {
            cout << "YES" << "\n";
            return;
        }
    }
    cout << "NO" << "\n";
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