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

void Test()
{
    int k = 0, n = 0;
    cin >> k >> n;

    int t = 1, ret = 1;
    cout << t << " ";
    for (int i = 2; i <= k; i++) {
        t += ret;
        ++ret;
        if (t > n - k + i) {
            t = n - k + i;
        }
        cout << t << " ";
    }
    cout << "\n";
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