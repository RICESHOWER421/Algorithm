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

    int ans = 0;
    while (n >= 2) {
        int a = 1, b = 2, c = 0, d = 1;
        while ((a + b) * 2 + c + d <= n) {
            a += b;
            ++b;
            c += d;
            ++d;
        }
        ++ans;
        n -= a * 2 + c;
    }
    cout << ans << "\n";
}

int main() {
    int test = 0;
    cin >> test;
    while (test--) {
        Test();
    }
    return 0;
}