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
    int left = 0, right = 0;
    int ret_1 = 0, ret_2 = 0, ret_3 = 0;
    int mn = INT_MAX;
    while (right < s.size()) {
        if (s[right] == '1') {
            ++ret_1;
        }
        else if (s[right] == '2') {
            ++ret_2;
        }
        else {
            ++ret_3;
        }

        if (ret_1 && ret_2 && ret_3) {
            while (ret_1 && ret_2 && ret_3) {
                mn = min(mn, right - left + 1);
                if (s[left] == '1') {
                    --ret_1;
                }
                else if (s[left] == '2') {
                    --ret_2;
                }
                else {
                    --ret_3;
                }
                ++left;
            }
        }
        ++right;
    }
    cout << (mn == INT_MAX ? 0 : mn) << "\n";
}

int main() {
    int test = 0;
    cin >> test;
    while (test--) {
        Test();
    }
    return 0;
}