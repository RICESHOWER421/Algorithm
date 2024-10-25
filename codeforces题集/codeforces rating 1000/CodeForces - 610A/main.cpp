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
    if (n % 2) {
        cout << 0 << "\n";
    }
    else {
        int ret = n / 2;
        cout << ret / 2 - (ret % 2 == 0) << "\n";
    }
}

int main() {
    Test();
    return 0;
}