#include <iostream>
#include <vector>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target) {
	//������������numsΪ0����ֱ�ӷ���{-1, -1}
	if (nums.size() == 0) return { -1, -1 };
	int begin = 0, end = 0;
	int left = 0, right = nums.size() - 1;
	//Ѱ��target��һ�γ��ֵ��±�
	while (left < right) { //������ȣ�����������ѭ��
		int mid = left + (right - left) / 2; //����ʹ��left + (right - left + 1) / 2������������ѭ��
		if (nums[mid] < target) left = mid + 1;
		else right = mid;
	}
	//�жϴ�ʱleft��rightָ����ǲ���targetֵ
	if (nums[left] == target) begin = left;
	else return { -1, -1 };

	//Ѱ��target���һ�γ��ֵ��±�
	right = nums.size() - 1; //left����Ҫ����Ϊ0����Ϊ��ʱleft����target��һ�γ��ֵ��±�
	while (left < right) { //�������ԭ����ͬ
		int mid = left + (right - left + 1) / 2;   //����ʹ��left + (right - left) / 2ԭ���������ͬ
		if (nums[mid] > target) right = mid - 1;
		else left = mid;
	}
	//�жϴ�ʱright�±�ָ���ֵ�ǲ���targetֵ
	if (nums[right] == target) {
		end = right;
		return { begin, end };
	}
	else return { -1, -1 };
}

int main() {
	vector<int> nums = { 5 };
	vector<int> return_nums = searchRange(nums, 5);
	cout << return_nums[0] << " " << return_nums[1] << endl;
	return 0;
}