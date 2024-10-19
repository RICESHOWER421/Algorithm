#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
typedef long long ll;
using namespace std;

void Test() {
    int n = 0, m = 0;
    cin >> n >> m;

    if ((ll)m * m > n || n % 2 != m % 2) {
        cout << "NO" << "\n";
    }
    else {
        cout << "YES" << "\n";
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