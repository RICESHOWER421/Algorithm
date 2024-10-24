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
    ll n = 0, k = 0;
    cin >> n >> k;

    if (n < k) {
        cout << "NO" << "\n";
        return;
    }

    if (n % 2 == k % 2) {
        cout << "YES" << "\n";
        for (int i = 0; i < k - 1; i++) {
            cout << 1 << " ";
        }
        cout << n - (k - 1) << "\n";
    }
    else {
        if (n % 2 == 0 && k % 2) {
            if (k <= n / 2) {
                cout << "YES" << "\n";
                for (int i = 0; i < k - 1; i++) {
                    cout << 2 << " ";
                }
                cout << n - 2 * (k - 1) << "\n";
            }
            else {
                cout << "NO" << "\n";
            }
        }
        else {
            cout << "NO" << "\n";
        }
    }
}

int main()
{
    int test = 0;
    cin >> test;
    while (test--) {
        Test();
    }
    return 0;
}