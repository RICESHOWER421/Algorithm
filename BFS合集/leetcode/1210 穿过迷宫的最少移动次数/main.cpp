#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct snake {
	snake(pair<int, int> tail, pair<int, int> head, int op) :_head(head), _tail(tail), _op(op) {}
	pair<int, int> _head, _tail;
	bool _op;	//蛇的状态，0表示躺着，1表示竖着 
};
int dx[2] = { 0,1 }, dy[2] = { 1, 0 };
class Solution {
public:
	int minimumMoves(vector<vector<int>>& grid) {
		map<pair<pair<int, int>, pair<int, int>>, bool> hash_map;	//第一个点表示尾巴的位置，第二个点表示头的位置
		int n = grid.size();
		queue<snake> q;
		q.push(snake({ 0,0 }, { 0,1 }, false));
		int cnt = 0;
		while (!q.empty()) {
			int sz = q.size();
			while (sz--) {
				auto tmp = q.front();
				q.pop();
				if (tmp._head.first == n - 1 && tmp._head.second == n - 1 && tmp._tail.first == n - 1 && tmp._tail.second == n - 2) return cnt;
				for (int i = 0; i < 2; i++) {
					int x1 = tmp._tail.first + dx[i], y1 = tmp._tail.second + dy[i], x2 = tmp._head.first + dx[i], y2 = tmp._head.second + dy[i];
					if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < n && x2 >= 0 && x2 < n && y2 >= 0 && y2 < n && !grid[x1][y1] && !grid[x2][y2] && !hash_map.count({ {x1, y1}, {x2,y2} })) {
						hash_map[{ {x1, y1}, { x2, y2 }}] = true;
						q.push(snake({ x1, y1 }, { x2, y2 }, tmp._op));
					}
				}

				int x = tmp._head.first + (tmp._op ? -1 : 1), y = tmp._head.second + (tmp._op ? 1 : -1);
				if (x >= 0 && x < n && y >= 0 && y < n && !grid[x][y] && !grid[tmp._tail.first + 1][tmp._tail.second + 1] && !hash_map.count({ {tmp._tail.first, tmp._tail.second},{x, y} })) {
					hash_map[{ {tmp._tail.first, tmp._tail.second}, { x, y }}] = true;
					q.push(snake({ tmp._tail.first, tmp._tail.second }, { x,y }, !tmp._op));
				}
			}
			++cnt;
		}
		return -1;
	}
};

int main()
{
	vector<vector<int>> grid = { {0,0,0,0,0,1},{1,1,0,0,1,0},{0,0,0,0,1,1},{0,0,1,0,1,0},{0,1,1,0,0,0},{0,1,1,0,0,0} };
	cout << Solution().minimumMoves(grid) << "\n";
	return 0;
}