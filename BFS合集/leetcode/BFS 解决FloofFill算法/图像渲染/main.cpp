#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
	int dx[4] = {0,0,-1,1};
	int dy[4] = { 1,-1,0,0 };
	int n = image.size(), m = image[0].size();
	int prev = image[sr][sc];
	if (prev == color) return image;

	queue<pair<int, int>> q;
	q.push({sr, sc});

	while (q.size()) {
		pair<int, int> arr = q.front();
		q.pop();
		image[arr.first][arr.second] = color;
		for (int i = 0; i < 4; i++) {
			int x = arr.first + dx[i], y = arr.second + dy[i];
			if (x >= 0 && x < n && y >= 0 && y < m && image[x][y] == prev)
				q.push({ x,y });
		}
	} 
	return image;
}

int main() {

	return 0;
}