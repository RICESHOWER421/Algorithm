#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
	unordered_map<int, vector<int>> edges;  //存储边的信息
	vector<int> nums(numCourses);			//存储点的入度信息

	//创建图
	for (auto& arr : prerequisites) {
		int num_1 = arr[0], num_2 = arr[1];
		edges[num_2].push_back(num_1);
		++nums[num_1];
	}

	queue<int> q;
	for (int i = 0; i < numCourses; i++)
		if (!nums[i]) q.push(i);  //如果有入度为0的点则放入队列中

	//进行拓扑排序
	while (q.size()) {
		int temp = q.front(); q.pop();
		for (auto num : edges[temp]) {
			--nums[num];
			if (!nums[num]) q.push(num); //如果又出现有点入度为0的情况，则添加进队列
		}
	}

	//最后判断这个图是不是有向无环图
	for (int i = 0; i < numCourses; i++)
		if (nums[i]) return false;

	return true;
}

int main() {
	vector<vector<int>> prerequisites = { {0,1}, {1,0} };
	cout << canFinish(2, prerequisites) << endl;
	return 0;
}