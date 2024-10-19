#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

void Test() {
    int n = 0;
    cin >> n;
    char a;
    cin >> a;
    string s;
    cin >> s;

    if (a == 'g') {
        cout << 0 << "\n";
        return;
    }

    vector<int> color, green;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'g') {
            green.push_back(i);
        }
        else if (s[i] == a) {
            color.push_back(i);
        }
    }

    sort(color.begin(), color.end());
    sort(green.begin(), green.end());
    int mx = -1;
    for (int i = 0; i < (int)color.size(); i++) {
        int left = 0, right = green.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (green[mid] < color[i]) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        int ans = (left == green.size() ? n - color[i] + green[0] : green[left] - color[i]);
        mx = max(mx, ans);
    }
    cout << mx << "\n";
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