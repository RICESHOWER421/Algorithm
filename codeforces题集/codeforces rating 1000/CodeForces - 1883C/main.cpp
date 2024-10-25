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
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> hash_map(5);
    for (int i = 0; i < n; i++) {
        int num = 0;
        cin >> num;
        hash_map[num % k]++;
    }

    if (hash_map[0]) {
        cout << 0 << "\n";
        return;
    }

    if (k == 2 || k == 3 || k == 5) {
        for (int i = k - 1; i >= 1; i--) {
            if (hash_map[i]) {
                cout << k - i << "\n";
                return;
            }
        }
    }
    else {
        if (hash_map[2] >= 2) {
            cout << 0 << "\n";
        }
        else if (hash_map[3] || hash_map[2] && hash_map[1]) {
            cout << 1 << "\n";
        }
        else {
            cout << 2 << "\n";
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