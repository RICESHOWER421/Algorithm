#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

int ways[4] = { -2, -1, 1, 2 }; //方位查找
int findway(int command, int way) {
	if (command == -2) {
		if (way > 0) way--;
		else way = 3;
	}
	else if (command == -1) {
		if (way < 3) way++;
		else way = 0;
	}
	return way;
}

int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
	unordered_map<int, vector<int>> hash_x;		//存储下标为x的障碍物
	unordered_map<int, vector<int>> hash_y;		//存储下标为y障碍物

	for (int i = 0; i < obstacles.size(); i++) {
		hash_x[obstacles[i][0]].push_back(obstacles[i][1]);
		hash_y[obstacles[i][1]].push_back(obstacles[i][0]);
	}

	int x = 0, y = 0;				//当前机器人的位置
	int way = 2;					//机器人的前进方向下标
	int max_num = -1;

	for (int i = 0; i < commands.size(); i++) {
		if (commands[i] == -1 || commands[i] == -2)
			way = findway(commands[i], way);
		else {
			int origin_x = x, origin_y = y;

			int temp = 0;   //判断是否在前进过程中遇到障碍物
			if (ways[way] == 2) {
				for (int j = 0; j < hash_y[origin_y].size(); j++) {
					if (origin_x < hash_y[origin_y][j] && hash_y[origin_y][j] <= origin_x + commands[i]) {
						if (x == origin_x) x = hash_y[origin_y][j] - 1;
						else x = min(hash_y[origin_y][j] - 1, x);
						temp = 1;
					}
				}
				if (!temp) x += commands[i];
			}
			else if (ways[way] == 1) {
				for (int j = 0; j < hash_x[origin_x].size(); j++) {
					if (origin_y < hash_x[origin_x][j] && hash_x[origin_x][j] <= origin_y + commands[i]) {
						if (y == origin_y) y = hash_x[origin_x][j] - 1;
						else y = min(y, hash_x[origin_x][j] - 1);
						temp = 1;
					}
				}
				if (!temp) y += commands[i];
			}
			else if (ways[way] == -1) {
				for (int j = 0; j < hash_y[origin_y].size(); j++) {
					if (origin_x > hash_y[origin_y][j] && hash_y[origin_y][j] >= origin_x - commands[i]) {
						if (x == origin_x) x = hash_y[origin_y][j] + 1;
						else x = max(x, hash_y[origin_y][j] + 1);
						temp = 1;
					}
				}
				if (!temp) x -= commands[i];
			}
			else {
				for (int j = 0; j < hash_x[origin_x].size(); j++) {
					if (origin_y > hash_x[origin_x][j] && hash_x[origin_x][j] >= origin_y - commands[i]) {
						if (y == origin_y) y = hash_x[origin_x][j] + 1;
						else y = max(y, hash_x[origin_x][j] + 1);
						temp = 1;
					}
				}
				if (!temp) y -= commands[i];
			}
		}
		
		//更新最远距离下标
		max_num = max(max_num, x * x + y * y);
	}

	return max_num;
}

int main() {
	vector<int> commands = { 3,-1,4,-1,5,-1,9,-1,-2,4,9,-1,-1,2 };
	vector<vector<int>> obstacles = { {2,4},{3,5},{4,6} };
	cout << robotSim(commands, obstacles) << endl;
	return 0;
}