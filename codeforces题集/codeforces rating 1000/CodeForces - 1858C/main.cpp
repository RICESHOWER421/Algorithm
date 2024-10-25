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

    for (int i = 2; i <= n / 2; i++) {
        int ret = i;
        while (ret <= n) {
            if (!vis[ret]) {
                vis[ret] = true;
                cout << ret << " ";
            }
            ret *= 2;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i]) {
            cout << i << " ";
        }
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