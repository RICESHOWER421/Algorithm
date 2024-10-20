#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <deque>
#include <queue>
#include <list>
typedef long long ll;
using namespace std;

void Test() {
	int n = 0, m = 0;
	cin >> n >> m;

	vector<vector<int>> grid(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	ll max_sum = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x = i, y = j;
			ll sum = grid[i][j];
			while (x - 1 >= 0 && y - 1 >= 0) sum += grid[--x][--y];

			x = i, y = j;
			while (x - 1 >= 0 && y + 1 < m) sum += grid[--x][++y];

			x = i, y = j;
			while (x + 1 < n && y - 1 >= 0) sum += grid[++x][--y];

			x = i, y = j;
			while (x + 1 < n && y + 1 < m) sum += grid[++x][++y];

			max_sum = max(max_sum, sum);
		}
	}
	cout << max_sum << endl;
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}