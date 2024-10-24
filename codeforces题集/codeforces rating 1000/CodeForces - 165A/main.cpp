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

    map<int, pair<int, int>> x, y;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
        if (!x.count(arr[i].first)) {
            x[arr[i].first] = { arr[i].second, arr[i].second };
        }
        else {
            x[arr[i].first].first = max(x[arr[i].first].first, arr[i].second);
            x[arr[i].first].second = min(x[arr[i].first].second, arr[i].second);
        }

        if (!y.count(arr[i].second)) {
            y[arr[i].second] = { arr[i].first, arr[i].first };
        }
        else
        {
            y[arr[i].second].first = max(y[arr[i].second].first, arr[i].first);
            y[arr[i].second].second = min(y[arr[i].second].second, arr[i].first);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].second != x[arr[i].first].first && arr[i].second != x[arr[i].first].second && arr[i].first != y[arr[i].second].first && arr[i].first != y[arr[i].second].second) {
            ++ans;
        }
    }
    cout << ans << "\n";
}

int main()
{
    Test();
    return 0;
}