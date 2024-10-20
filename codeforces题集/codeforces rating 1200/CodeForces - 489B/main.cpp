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
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int m = 0;
    cin >> m;
    vector<int> g(m);
    for (int i = 0; i < m; i++) {
        cin >> g[i];
    }

    sort(b.begin(), b.end());
    sort(g.begin(), g.end());

    int ans = 0;
    int left = 0, right = 0;
    while (left < n && right < m) {
        if (abs(b[left] - g[right]) <= 1) {
            ++ans;
            ++left;
            ++right;
        }
        else {
            if (left + 1 != n && b[left] < g[right]) {
                ++left;
            }
            else {
                ++right;
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    Test();
    return 0;
}