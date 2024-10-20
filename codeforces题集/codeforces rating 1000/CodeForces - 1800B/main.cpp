#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
typedef long long ll;
using namespace std;

void Test() {
    int n = 0, k = 0;
    cin >> n >> k;
    string s;
    cin >> s;
    map<char, int> hash_map;
    for (auto& x : s) {
        hash_map[x]++;
    }

    int ans = 0;
    int temp = 0;
    for (char i = 'a'; i <= 'z'; i++) {
        ans += min(hash_map[i], hash_map[i - ' ']);
        temp += (hash_map[i] + hash_map[i - ' ']) / 2 - min(hash_map[i], hash_map[i - ' ']);
    }
    cout << ans + min(temp, k) << "\n";
}

int main() {
    int test = 0;
    cin >> test;

    while (test--) {
        Test();
    }
    return 0;
}