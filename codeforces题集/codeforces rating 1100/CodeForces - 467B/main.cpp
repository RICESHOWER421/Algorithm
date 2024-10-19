#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
typedef long long ll;
using namespace std;

void Test()
{
    int n = 0, m = 0, k = 0;
    cin >> n >> m >> k;
    vector<int> nums(m + 1);
    for (int i = 0; i <= m; i++)
    {
        cin >> nums[i];
    }

    vector<int> ret(n);
    for (int i = 0; i < n; i++)
    {
        ret[i] = nums[m] & 1;
        nums[m] >>= 1;
    }

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        int time = 0;
        bool ok = true;
        for (int j = 0; j < n; j++)
        {
            if ((nums[i] & 1) != ret[j])
            {
                ++time;
            }
            if (time > k)
            {
                ok = false;
                break;
            }
            nums[i] >>= 1;
        }
        if (ok)
        {
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