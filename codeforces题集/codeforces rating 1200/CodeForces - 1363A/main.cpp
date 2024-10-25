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
    int n = 0, k = 0;
    cin >> n >> k;

    int ret_1 = 0, ret_2 = 0;
    for (int i = 0; i < n; i++) {
        int num = 0;
        cin >> num;
        if (num % 2) {
            ++ret_2;
        }
        else {
            ++ret_1;
        }
    }

    ret_2 = min(ret_2, k);
    if (ret_2 > 0 && k - (ret_2 - (ret_2 % 2 == 0)) <= ret_1) {
        cout << "Yes" << "\n";
    }
    else {
        cout << "No" << "\n";
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