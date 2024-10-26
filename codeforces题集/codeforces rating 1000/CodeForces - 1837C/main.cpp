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

    string ret;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '?') {
            if (i == 0) {
                ret += '0';
            }
            else {
                ret += ret.back();
            }
        }
        else {
            ret += s[i];
        }
    }
    cout << ret << "\n";
}

int main() {
    int test = 0;
    cin >> test;
    while (test--) {
        Test();
    }
    return 0;
}