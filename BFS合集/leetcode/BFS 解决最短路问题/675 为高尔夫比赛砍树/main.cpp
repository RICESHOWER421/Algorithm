#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cstring>
using namespace std;

int dx[4] = { 0, 0,-1,1};
int dy[4] = { 1,-1,0,0 };
int cutOffTree(vector<vector<int>>& forest) {
	int m = forest.size(), n = forest[0].size();
	unordered_map<int, pair<int, int>> hash;
	vector<int> nums;
	bool vis[51][51] = {0};

	//������ά����forest
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (forest[i][j] != 0 && forest[i][j] != 1) {
				hash[forest[i][j]] = {i, j};
				nums.push_back(forest[i][j]);
			}
		}
	}
	
	int ret = 0;
	sort(nums.begin(), nums.end());
	/*���ϴ���û����*/
	queue<pair<int, int>> q;
	q.push({0,0});

	int sum = nums.size();
	int index = 0;
	for (int i = 0; i < sum; i++) {
		bool vis[51][51] = { 0 };
		pair<int, int> end;
		if (nums[0] == forest[0][0]) {
			end = hash[nums[i + 1]];
			if (!index) {
				sum -= 1;
				index = 1;
			}
		}
		else end = hash[nums[i]];

		int temp = 0;
		while (q.size()) {
			int size = q.size();
			if (!temp) ++ret;
			while (size--) {
				pair<int, int> begin = q.front();
				q.pop();
				if (temp != 1) { //��������ҵ������·����ֱ�ӽ���������Ԫ��ȫ����������
					for (int j = 0; j < 4; j++) {
						int x = begin.first + dx[j], y = begin.second + dy[j];
						if (x >= 0 && x < m && y >= 0 && y < n && forest[x][y] != 0 && !vis[x][y]) {
							if (x == end.first && y == end.second) {
								temp = 1;
								break;
							}
							q.push({ x,y });
							vis[x][y] = true;
						}
					}
				}
			}

			//�����ѭ��ʱ���д�СΪ0����tempֵΪ0��˵�����Ǹ���������Ҫ������һ������λ�ã�ֱ�ӷ���-1
			if (q.size() == 0 && temp == 0) return -1;
		}
		q.push(end);          //����n - 1�ֵ��յ�����Ϊ��n�ֵ����
	}
	return ret;
}

int main() {
	vector<vector<int>> forest = { {1,2,3},{0,0,4},{7,6,5} };
	cout << cutOffTree(forest) << endl;
	return 0;
}