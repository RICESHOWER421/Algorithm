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
    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<char>> grids(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grids[i][j];
        }
    }

    if (m % 2) {
        char a = 'B';
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grids[i][j] == '.') {
                    cout << a;
                }
                else {
                    cout << grids[i][j];
                }
                if (a == 'W') {
                    a = 'B';
                }
                else {
                    a = 'W';
                }
            }
            cout << "\n";
        }
    }
    else {
        for (int i = 0; i < n; i++)
        {
            char a = i % 2 == 0 ? 'B' : 'W';
            for (int j = 0; j < m; j++)
            {
                if (grids[i][j] == '.')
                {
                    cout << a;
                }
                else
                {
                    cout << grids[i][j];
                }
                if (a == 'W')
                {
                    a = 'B';
                }
                else
                {
                    a = 'W';
                }
            }
            cout << "\n";
        }
    }
}

int main() {
    Test();
    return 0;
}