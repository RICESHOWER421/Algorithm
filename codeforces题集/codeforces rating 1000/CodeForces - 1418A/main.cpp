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
    ll x = 0, y = 0, k = 0;
    cin >> x >> y >> k;
    cout << k + (y * k + k - 1) / (x - 1) + ((y * k + k - 1) % (x - 1) != 0) << "\n";
}

int main() {
    int test = 0;
    cin >> test;
    while (test--) {
        Test();
    }
    return 0;
}