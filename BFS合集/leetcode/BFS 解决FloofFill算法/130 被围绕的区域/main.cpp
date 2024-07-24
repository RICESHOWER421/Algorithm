#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int m = 0, n = 0;

void bfs(vector<vector<char>>& board, vector<vector<bool>>& vis, int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i, j });

	while (q.size()) {
		pair<int, int> arr = q.front();
		q.pop();
		if (i != 0 && i != m - 1 && j != n - 1 && j != 0) {
			board[arr.first][arr.second] = 'X';
		}
		vis[arr.first][arr.second] = true;

		for (int k = 0; k < 4; k++) {
			int x = arr.first + dx[k], y = arr.second + dy[k];
			if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'O' && !vis[x][y]) {
				q.push({ x, y });
				if (i != 0 && i != m - 1 && j != n - 1 && j != 0) board[x][y] = 'X';
				vis[x][y] = true;
			}
		}
	}
}

void solve(vector<vector<char>>& board) {
	m = board.size(), n = board[0].size();
	vector<vector<bool>> vis(m, vector<bool>(n));
	//首先先排除第一行、最后一行以及第一列，最后一列的情况
	//一定是要将第一行和第一列的情况也要提前考虑
	for (int i = 0; i < m; i++) {
		if (board[i][0] == 'O' && !vis[i][0])
			bfs(board, vis, i, 0);
		if (board[i][n - 1] == 'O' && !vis[i][n - 1])
			bfs(board, vis, i, n - 1);
	}
	for (int i = 0; i < n; i++) {
		if (board[0][i] == 'O' && !vis[0][i])
			bfs(board, vis, 0, i);
		if (board[m - 1][i] == 'O' && !vis[m - 1][i])
			bfs(board, vis, m - 1, i);
	}

	for (int i = 0; i < m - 1; i++)
		for (int j = 0; j < n - 1; j++)
			if (board[i][j] == 'O' && !vis[i][j])
				bfs(board, vis, i, j);
}

int main() {
	vector<vector<char>> board = { {'X','O','X','O','X','O'},
								   {'O','X','O','X','O','X'},
								   {'X','O','X','O','X','O'},
								   {'O','X','O','X','O','X'},};
	solve(board);
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}