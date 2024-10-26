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

    vector<int> nums(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    nums.push_back(-1);

    if (n == 1) {
        cout << -1 << "\n";
        return;
    }

    bool ok = false;
    int left = 1, right = 2;
    vector<int> ans;
    while (right < nums.size()) {
        if (nums[left] != nums[right] && !ok) {
            cout << -1 << "\n";
            return;
        }
        else if (nums[left] != nums[right] && ok) {
            ok = false;
            int begin = left;
            while (left < right) {
                if (left != right - 1) {
                    ans.push_back(left + 1);
                }
                else {
                    ans.push_back(begin);
                }
                ++left;
            }
        }
        else {
            ok = true;
        }
        ++right;
    }

    for (auto& x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int test = 0;
    cin >> test;
    while (test--) {
        Test();
    }
    return 0;
}