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
    int k = 0;
    cin >> k;

    int pos = 0;
    int begin = 19;
    int ans = -1;
    while (pos < k) {
        int sum = 0;
        int ret = begin;
        while (ret) {
            sum += ret % 10;
            ret /= 10;
        }

        if (sum == 10) {
            ++pos;
            ans = begin;
        }
        ++begin;
    }
    cout << ans << "\n";
}

int main()
{
    Test();
    return 0;
}