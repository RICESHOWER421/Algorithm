#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dx[4] = { 0,0,-1,1};
int dy[4] = { 1,-1,0,0 };
int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
	int m = maze.size(), n = maze[0].size();
	vector <vector<bool>> vis(m, vector<bool>(n));

	queue<pair<int, int>> q;
	q.push({entrance[0], entrance[1]});
	vis[entrance[0]][entrance[1]] = true;
	int step = 0;

	while (q.size()) {
		++step;
		int size = q.size();
		for (int k = 0; k < size; k++) {
			pair<int, int>arr = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int x = arr.first + dx[i], y = arr.second + dy[i];
				if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && maze[x][y] == '.') {
					if (x == 0 || x == m - 1 || y == 0 || y == n - 1) return step;
					q.push({ x,y });
					vis[x][y] = true;
				}
			}
		}
	}
	return -1;
}

int main() {
	vector<vector<char>> maze = { {'+', '+', '.', '+'},
								  {'.', '.', '.', '+'},
								  {'+', '+', '+', '.'}};
	vector<int> entrance = { 1,2 };
	cout << nearestExit(maze, entrance) << endl;
	return 0;
}