#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
	unordered_map<int, vector<int>> edges;   //�洢�ߵ���Ϣ
	vector<int> nums(numCourses);			 //�洢��������Ϣ
	vector<int> return_nums;                 //�γ̱���

	//����ͼ
	for (auto& arr : prerequisites) {
		int num_1 = arr[0], num_2 = arr[1];
		edges[num_2].push_back(num_1);
		++nums[num_1];
	}

	//�Ƚ����Ϊ0�ĵ���������
	queue<int> q;
	for (int i = 0; i < numCourses; i++)
		if (!nums[i]) q.push(i);

	//������������
	while (q.size()) {
		int num = q.front(); q.pop();
		return_nums.push_back(num);
		for (auto n : edges[num]) {
			--nums[n];
			if (!nums[n]) q.push(n);
		}
	}

	//���������޻�ͼ���ж�
	for (int i = 0; i < numCourses; i++)
		if (nums[i]) return {};
	return return_nums;
}

int main() {
	vector<vector<int>> prerequisites = { {1,0},{2,0},{3,1},{3,2} };
	vector<int> return_nums = findOrder(4, prerequisites);
	for (int i = 0; i < return_nums.size(); i++)
		cout << return_nums[i] << " ";
	cout << endl;
	return 0;
}