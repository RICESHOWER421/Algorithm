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
    int a = 0, b = 0, c = 0;
    cin >> a >> b >> c;

    int ret_1 = sqrt(b * c / a), ret_2 = c / ret_1, ret_3 = a / ret_2;
    cout << ret_1 * 4 + ret_2 * 4 + ret_3 * 4 << "\n";
}

int main() {
    Test();
    return 0;
}