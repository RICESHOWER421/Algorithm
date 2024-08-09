#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//̰��+�������ۣ�ϸ�ڷǳ��࣬����ϸд�Ļ�������д������wa�����Σ�һ���ּ���һ��ϸ�ڴ���
//int largestSumAfterKNegations(vector<int>& nums, int k) {
//	sort(nums.begin(), nums.end());
//	int index = 0;	//��¼�Ƿ����0
//	int max_num = INT_MIN; //��¼���и��������ֵ
//	int min_num = INT_MAX; //��¼������������Сֵ
//	int ans = 0;		//����ֵ
//	int temp = 0;		//��¼�����ĸ���
//	for (int i = 0; i < nums.size(); i++) {
//		if (nums[i] == 0) index = 1;
//		else if (nums[i] < 0) {
//			++temp;
//			max_num = max(max_num, nums[i]);
//		}
//		else min_num = min(min_num, nums[i]);
//	}
//
//	if (temp > 0) {		//������ڸ���
//		if (temp > k) {	//����������k�Ĵ�������
//			for (int i = 0; i < nums.size(); i++) {
//				if (i < k) ans += abs(nums[i]);
//				else ans += nums[i];
//			}
//		}
//		else {	//����������k����Ҫ��
//			if (temp % 2 == k % 2) {		//��������������ú�k�Ĵ�Сͬ��ż��
//				for (int i = 0; i < nums.size(); i++) {
//					ans += abs(nums[i]);
//				}
//			}
//			else {	//��ͬ��ż��
//				if (index) {	//�������0����ô�Ϳ���ȫ��ת��Ϊ����
//					for (int i = 0; i < nums.size(); i++) {
//						ans += abs(nums[i]);
//					}
//				}
//				else {			//������0�Ļ�
//					if (abs(max_num) > min_num) {	//������������ֵ�ľ���ֵ����������Сֵ��Ҫ�������и�����Ϊ��������С��������Ϊ����
//						for (int i = 0; i < nums.size(); i++) {
//							if (nums[i] != min_num) ans += abs(nums[i]);
//							else ans += ( - nums[i]);
//						}
//					}
//					else {
//						int k = 0;	//�����ֻ�������ĸ������ڣ���ע��ֻ����һ�����ĸ�������
//						for (int i = 0; i < nums.size(); i++) {
//							if (max_num == nums[i]) {
//								if (!k) {
//									ans += nums[i];
//									k = 1;
//								}
//								else ans += abs(nums[i]);
//							}
//							else ans += abs(nums[i]);
//						}
//					}
//				}
//			}
//		}
//	}
//	else {
//		if (index) { //�������0��û��������ɸ���
//			for (int i = 0; i < nums.size(); i++) {
//				ans += nums[i];
//			}
//		}
//		else {		//���������0
//			if (k % 2 == 0) {//���k�Ĵ�������Ϊż����ͬ��û��������ɸ���
//				for (int i = 0; i < nums.size(); i++) {
//					ans += nums[i];
//				}
//			}
//			else {		//���k�Ĵ���Ϊ��������ô��С��������Ҫ��Ϊ����
//				for (int i = 0; i < nums.size(); i++) {
//					if (i == 0) ans += (-nums[i]);
//					else ans += nums[i];
//				}
//			}
//		}
//	}
//	return ans;
//}

//��д�汾
int largestSumAfterKNegations(vector<int>& nums, int k) {
	sort(nums.begin(), nums.end());
	int sum = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] < 0 && k) {
			nums[i] = -nums[i];
			--k;
		}
		sum += nums[i];
	}
	if (k == 0) return sum;
	else {
		if (k % 2 == 0) return sum;
		else {
			sort(nums.begin(), nums.end());
			return sum - 2 * nums[0];
		}
	}
}

int main() {
	vector<int> nums = { 8,-7,-3,-9,1,9,-6,-9,3 };
	int k = 8;
	cout << largestSumAfterKNegations(nums, k) << endl;
	return 0;
}