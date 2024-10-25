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
    int n = 0;
    cin >> n;
    string s;
    cin >> s;

    string s1, s2;
    bool ok = false;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            s1 += '1';
            s2 += '1';
        }
        else {
            if (s[i] == '0') {
                s1 += '0';
                s2 += '0';
            }
            else if (s[i] == '1') {
                if (ok) {
                    s1 += '0';
                    s2 += '1';
                }
                else {
                    s1 += '1';
                    s2 += '0';
                    ok = true;
                }
            }
            else {
                if (ok) {
                    s1 += '0';
                    s2 += '2';
                }
                else {
                    s1 += '1';
                    s2 += '1';
                }
            }
        }
    }
    cout << s1 << "\n";
    cout << s2 << "\n";
}

int main() {
    int test = 0;
    cin >> test;
    while (test--) {
        Test();
    }
    return 0;
}