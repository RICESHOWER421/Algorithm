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
    int n = 0, c = 0, d = 0;
    cin >> n >> c >> d;

    ll mn = INT_MAX;
    map<ll, int> hash_map;
    for (int i = 0; i < n * n; i++) {
        ll num = 0;
        cin >> num;
        hash_map[num]++;
        mn = min(mn, num);
    }

    for (int i = 0; i < n; i++) {
        ll ret = mn;
        for (int j = 0; j < n; j++) {
            if (!hash_map[ret]) {
                cout << "NO" << "\n";
                return;
            }
            else {
                hash_map[ret]--;
            }
            ret += c;
        }
        mn += d;
    }
    cout << "YES" << "\n";
}

int main() {
    int test = 0;
    cin >> test;
    while (test--) {
        Test();
    }
    return 0;
}