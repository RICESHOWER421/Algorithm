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
    sort(nums.begin(), nums.end());
    for (int i = 1; i < n; i++) {
        cout << nums[i] << " " << nums[0] << "\n";
        if (i == n / 2) {
            break;
        }
    }
}

int main() {
    int test = 0;
    cin >> test;
    while (test--) {
        Test();
    }
    return 0;
}