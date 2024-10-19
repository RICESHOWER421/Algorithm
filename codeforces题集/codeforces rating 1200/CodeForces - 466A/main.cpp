#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
typedef long long ll;
using namespace std;

//注意可以花钱多座站
void Test()
{
    int n = 0, m = 0, a = 0, b = 0;
    cin >> n >> m >> a >> b;

    if (a * m > b)
    {
        int ans = (n / m) * b;
        if ((n % m) * a > b)
        {
            ans += b;
        }
        else
        {
            ans += (n % m) * a;
        }
        cout << ans << "\n";
    }
    else
    {
        cout << n * a << "\n";
    }
}

int main()
{
    Test();
    return 0;
}