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

map<ll, int> hash_map;
void Test() {
    ll n = 0;
    cin >> n;
    ll begin = 1;
    while ((ll)pow(begin, 3) <= 1e12 && (ll)pow(begin, 3) <= n) {
        if (hash_map.count(n - (ll)pow(begin, 3))) {
            cout << "YES" << "\n";
            return;
        }
        ++begin;
    }
    cout << "NO" << "\n";
}

int main() {
    int test = 0;
    cin >> test;
    ll begin = 1;
    while ((ll)pow(begin, 3) <= 1e12) {
        hash_map[(ll)pow(begin, 3)] = 1;
        ++begin;
    }

    while (test--) {
        Test();
    }
    return 0;
}