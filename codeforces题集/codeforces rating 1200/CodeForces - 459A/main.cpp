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
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    cin >> x1 >> y1 >> x2 >> y2;

    if (x1 == x2) {
        cout << x1 + abs(y1 - y2) << " " << y1 << " " << x2 + abs(y1 - y2) << " " << y2 << "\n";
    }
    else if (y1 == y2) {
        cout << x1 << " " << y1 + abs(x1 - x2) << " " << x2 << " " << y2 + abs(x1 - x2) << "\n";
    }
    else {
        if (abs(x1 - x2) != abs(y1 - y2)) {
            cout << -1 << "\n";
        }
        else {
            cout << x2 << " " << y1 << " " << x1 << " " << y2 << "\n";
        }
    }
}

int main() {
    Test();
    return 0;
}