#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
using namespace std;

void Test() {
    int n = 0, m = 0;
    cin >> n >> m;
    if (m > n) {
        cout << "NO" << "\n";
    }
    else if (m == n) {
        cout << "YES" << "\n";
    }
    else {
        priority_queue<int> pq;
        pq.push(n);
        while (!pq.empty()) {
            int ret = pq.top();
            pq.pop();
            if (ret % 3 == 0) {
                if (ret / 3 == m || ret / 3 * 2 == m) {
                    cout << "YES" << "\n";
                    return;
                }
                pq.push(ret / 3);
                pq.push(ret / 3 * 2);
            }
        }
        cout << "NO" << "\n";
    }
}

int main()
{
    int test = 0;
    cin >> test;
    while (test--)
    {
        Test();
    }
    return 0;
}