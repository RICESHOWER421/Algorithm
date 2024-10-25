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
    int n = 0, m = 0, x = 0, y = 0, d = 0;
    cin >> n >> m >> x >> y >> d;
    if (x + d >= n && y + d >= m || x - d <= 1 && y - d <= 1 || x + d >= n && x - d <= 1 || y + d >= m && y - d <= 1) {
        cout << -1 << "\n";
    }
    else {
        cout << n - 1 + m - 1 << "\n";
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