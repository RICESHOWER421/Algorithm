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
    string s;
    cin >> s;

    int ret_1 = 0, ret_2 = 0;
    for (auto& x : s) {
        if (x == '0') {
            ++ret_1;
        }
        else {
            ++ret_2;
        }
    }

    int ans = 0;
    for (auto& x : s) {
        if (x == '0') {
            if (ret_2) {
                --ret_2;
                ++ans;
            }
            else {
                break;
            }
        }
        else {
            if (ret_1) {
                --ret_1;
                ++ans;
            }
            else {
                break;
            }
        }
    }
    cout << s.size() - ans << "\n";
}

int main() {
    int test = 0;
    cin >> test;
    while (test--) {
        Test();
    }
    return 0;
}