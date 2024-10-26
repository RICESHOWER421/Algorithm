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

int arr[300001];
void Test() {
    int n = 0, k = 0;
    cin >> n >> k;

    if (arr[n] == k) {
        cout << n << "\n";
    }
    else if ((arr[n] ^ k) == n) {
        cout << n + 2 << "\n";
    }
    else {
        cout << n + 1 << "\n";
    }
}

int main() {
    for (int i = 1; i < 300001; i++) {
        arr[i] = arr[i - 1] ^ (i - 1);
    }
    int test = 0;
    cin >> test;
    while (test--) {
        Test();
    }
    return 0;
}