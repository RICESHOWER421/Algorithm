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
    int a = 0, b = 0, c = 0, d = 0, e = 0;
    cin >> a >> b >> c >> d >> e;
    if ((a + b + c + d + e) % 5 == 0 && a + b + c + d + e != 0) {
        cout << (a + b + c + d + e) / 5 << "\n";
    }
    else {
        cout << "-1" << "\n";
    }
}

int main() {
    Test();
    return 0;
}