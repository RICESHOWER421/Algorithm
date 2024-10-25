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

    map<int, int> hash_map;
    vector<int> ret;
    for (int i = 0; i < n; i++)
    {
        int num = 0;
        cin >> num;
        if (!hash_map.count(num))
        {
            ret.push_back(num);
        }
        hash_map[num]++;
    }
    sort(ret.begin(), ret.end());

    if (k == 0) {
        if (ret[0] == 1) {
            cout << -1 << "\n";
        }
        else {
            cout << 1 << "\n";
        }
        return;
    }
    int sum = 0;
    for (int i = 0; i < ret.size(); i++)
    {
        sum += hash_map[ret[i]];
        if (sum > k)
        {
            cout << -1 << "\n";
            return;
        }
        else if (sum == k)
        {
            cout << ret[i] << "\n";
            return;
        }
    }
}

int main()
{
    Test();
    return 0;
}