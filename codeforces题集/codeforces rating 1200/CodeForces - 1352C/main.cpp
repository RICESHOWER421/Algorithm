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
    ll a = 0, b = 0;
    cin >> a >> b;
    ll ans = b % (a - 1) == 0 ? b / (a - 1) * a - 1 : b / (a - 1) * a + (b % (a - 1));
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