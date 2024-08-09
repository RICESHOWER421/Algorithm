#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//�������Ƕ����������������
//��Ϊnums1ɾ������Ԫ��֮��ʣ�µ�ֵ��nums2��ֵ�����ֵ��һ���ģ��������ǿ���֪��ǰ����ֵ��һ����һ��ֵ��ɾ������Ҫ������
//�������ǾͿ�����nums1ǰ��������nums2�ĵ�һ��ֵ�Ĳ�ֵ����ö�٣�Ѱ�Ҳ�ֵһ���������оͿ�����
//Ψһ��ϸ�ھ��ǣ������Ǵӵ���������ʼ�����ģ���ΪҪ���ص�������ֵ������Խ���ұߵ�����ֵ�ͻ�Խ��
int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());

	for (int i = 2; i >= 0; i--) {
		int num = nums2[0] - nums1[i];
		int index = 0;
		for (int j = i; j < nums1.size(); j++) {
			if (nums1[j] + num == nums2[index]) ++index;
			if (index == nums2.size()) return num;
		}
	}
	return 0;
}

int main() {
	vector<int> nums1 = { 3,5,5,3};
	vector<int> nums2 = { 7,7 };
	cout << minimumAddedInteger(nums1, nums2) << endl;
	return 0;
}