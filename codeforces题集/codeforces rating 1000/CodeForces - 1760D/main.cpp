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
    int n = 0;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    if (n == 1)
    {
        cout << "YES" << "\n";
        return;
    }

    vector<int> ret;
    ret.push_back(nums[0]);
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != ret.back())
        {
            ret.push_back(nums[i]);
        }
    }

    bool ok = false; // false表示下降,true表示上升
    for (int i = 1; i < ret.size(); i++)
    {
        if (ret[i] > ret[i - 1])
        {
            if (!ok)
            {
                ok = true;
            }
        }
        else {
            if (ok) {
                cout << "NO" << "\n";
                return;
            }
        }
    }
    cout << "YES" << "\n";
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