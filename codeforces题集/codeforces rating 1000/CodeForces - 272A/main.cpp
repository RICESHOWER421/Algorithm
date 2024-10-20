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

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int num = 0;
        cin >> num;
        sum += num;
    }

    int ans = 0;
    for (int i = 1; i <= 5; i++) {
        if ((sum + i) % (n + 1) != 1) {
            ++ans;
        }
    }
    cout << ans << "\n";
}

int main() {
    Test();
    return 0;
}