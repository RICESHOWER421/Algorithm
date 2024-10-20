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
    int n = 0;
    cin >> n;
    vector<int> ans;
    map<int, int> hash_map;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int num = 0;
        cin >> num;
        if (!hash_map.count(num)) {
            ans.push_back(num);
        }
        hash_map[num]++;
        mx = max(hash_map[num], mx);
    }
    cout << mx << " " << ans.size() << "\n";
}
int main() {
    Test();
    return 0;
}