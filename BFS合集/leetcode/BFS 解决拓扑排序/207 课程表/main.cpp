#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
	unordered_map<int, vector<int>> edges;  //�洢�ߵ���Ϣ
	vector<int> nums(numCourses);			//�洢��������Ϣ

	//����ͼ
	for (auto& arr : prerequisites) {
		int num_1 = arr[0], num_2 = arr[1];
		edges[num_2].push_back(num_1);
		++nums[num_1];
	}

	queue<int> q;
	for (int i = 0; i < numCourses; i++)
		if (!nums[i]) q.push(i);  //��������Ϊ0�ĵ�����������

	//������������
	while (q.size()) {
		int temp = q.front(); q.pop();
		for (auto num : edges[temp]) {
			--nums[num];
			if (!nums[num]) q.push(num); //����ֳ����е����Ϊ0�����������ӽ�����
		}
	}

	//����ж����ͼ�ǲ��������޻�ͼ
	for (int i = 0; i < numCourses; i++)
		if (nums[i]) return false;

	return true;
}

int main() {
	vector<vector<int>> prerequisites = { {0,1}, {1,0} };
	cout << canFinish(2, prerequisites) << endl;
	return 0;
}