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
    int n = 0;
    cin >> n;

    vector<int> nums(n);
    map<int, int> hash_map;
    int ret_1 = 0, ret_2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        hash_map[nums[i]] = 1;
        if (nums[i] % 2 == 0) {
            ++ret_1;
        }
        else {
            ++ret_2;
        }
    }

    if (ret_1 % 2 == 0 && ret_2 % 2 == 0) {
        cout << "YES" << "\n";
        return;
    }

    for (auto& x : nums) {
        if (hash_map.count(x + 1) || hash_map.count(x - 1)) {
            cout << "YES" << "\n";
            return;
        }
    }
    cout << "NO" << "\n";
}

int main() {
    int test = 0;
    cin >> test;
    while (test--) {
        Test();
    }
    return 0;
}