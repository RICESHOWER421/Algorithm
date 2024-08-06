#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

//���Ѷ��Ļ������ڣ����ʹ�û������ڵĻ�ϸ�ںܶ࣬���ҷǳ����ӡ�
//����ʹ������forѭ������Ϊһ���Ǵ�������ժ��һ����������ժ�������������һ��ȡ���ֵ����֮д�ķǳ����ӡ�
//���һ����˹�ϣ�洢ÿ��λ�õ�ˮ�����Ա�ÿ���ƶ����ڱ߽�ʱ����֪�����λ���Ƿ����ˮ��������ʱ�临�Ӷ��е��
//������д�����ˣ�ֻ��˵�ܹ�����:)
int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
	int ans = 0;

	map<int, int> hash_map;
	for (int i = 0; i < fruits.size(); i++) hash_map[fruits[i][0]] = fruits[i][1];

	int left = startPos - k, right = startPos;
	int sum = 0;
	for (int i = 0; i < fruits.size(); i++) {
		if (fruits[i][0] < left) continue;
		else if (fruits[i][0] >= left && fruits[i][0] <= right) sum += fruits[i][1];
		else {
			int temp = fruits[i][0] - startPos;
			if (temp > k / 2) break;
			else {
				int num = fruits[i][0] - right;
				right = fruits[i][0];
				sum += fruits[i][1];
				while (num--) {
					if (hash_map.count(left)) sum -= hash_map[left];
					++left;
					if (hash_map.count(left)) sum -= hash_map[left];
					++left;
				}
			}
		}
		ans = max(sum, ans);
	}

	left = startPos, right = startPos + k;
	sum = 0;
	for (int i = fruits.size() - 1; i >= 0; i--) {
		if (fruits[i][0] > right) continue;
		if (fruits[i][0] <= right && fruits[i][0] >= left) sum += fruits[i][1];
		else {
			int temp = left - startPos;
			if (temp > k / 2) break;
			else {
				int num = left - fruits[i][0];
				left = fruits[i][0];
				sum += fruits[i][1];
				while (num--) {
					if (hash_map.count(right)) sum -= hash_map[right];
					--right;
					if (hash_map.count(right)) sum -= hash_map[right];
					--right;
				}
			}
		}
		ans = max(ans, sum);
	}
	return ans;
}

int main() {
	vector<vector<int>> fruits = { {0,3},{6,4},{8,5} };
	int startPos = 3, k = 2;
	cout << maxTotalFruits(fruits, startPos, k) << endl;
	return 0;
}