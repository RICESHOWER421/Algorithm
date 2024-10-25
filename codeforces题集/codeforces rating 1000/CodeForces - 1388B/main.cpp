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
    int ret = n / 4 + (n % 4 != 0);
    for (int i = 0; i < n - ret; i++) {
        cout << "9";
    }
    for (int i = 0; i < ret; i++) {
        cout << "8";
    }
    cout << "\n";
}

int main() {
    int test = 0;
    cin >> test;
    while (test--) {
        Test();
    }
    return 0;
}