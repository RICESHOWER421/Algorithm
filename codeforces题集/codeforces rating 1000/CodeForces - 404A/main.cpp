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
    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    char ret_1 = arr[0][0], ret_2 = arr[0][1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || i + j == n - 1) {
                if (arr[i][j] != ret_1) {
                    cout << "NO" << "\n";
                    return;
                }
            }
            else {
                if (arr[i][j] == ret_1 || arr[i][j] != ret_2) {
                    cout << "NO" << "\n";
                    return;
                }
            }
        }
    }
    cout << "YES" << "\n";
}

int main()
{
    Test();
    return 0;
}