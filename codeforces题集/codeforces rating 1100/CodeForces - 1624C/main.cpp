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

    vector<bool> vis(n + 1);
    for (int i = 0; i < n; i++) {
        int num = 0;
        cin >> num;
        while (num) {
            if (num >= 1 && num <= n && !vis[num]) {
                vis[num] = true;
                break;
            }
            num /= 2;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << "NO" << "\n";
            return;
        }
    }
    cout << "YES" << "\n";
}

int main() {
    int test = 0;
    cin >> test;
    while (test--) {
        Test();
    }
    return 0;
}