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
    ll a = 0, b = 0;
    cin >> a >> b;
    if (a == b) {
        cout << 0 << "\n";
    }
    else {
        if (a > b) {
            swap(a, b);
        }

        if (b % 2) {
            cout << -1 << "\n";
        }
        else {
            int ret = 0;
            while (a != b) {
                if (a * 8 <= b) {
                    a *= 8;
                }
                else if (a * 4 <= b) {
                    a *= 4;
                }
                else if (a * 2 <= b) {
                    a *= 2;
                }
                else {
                    ret = -1;
                    break;
                }
                ++ret;
            }
            cout << ret << "\n";
        }
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