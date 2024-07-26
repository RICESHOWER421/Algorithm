#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int totalFruit(vector<int>& fruits) {
	int n = fruits.size();
	int temp_1 = -1, temp_2 = -1;  //���ֲ�ͬ��ˮ������
	int temp_1_num = 1, temp_2_num = 1;  //���ֲ�ͬˮ�����͵ĸ���
	int left = 0, right = 0, max_len = -1;
	while (right <= n - 1) {
		//�ؼ��㣬���ѷ�����һ�����ڣ���left�ڻ��������е�λ��������
		if (fruits[right] != temp_1 || fruits[right] != temp_2) { //����������������������������ˮ��
			if (fruits[right] == temp_1 || fruits[right] == temp_2) {
				if (fruits[right] == temp_1) ++temp_1_num;    //���ֵ�һ��ˮ���ĸ���
				if (fruits[right] == temp_2) ++temp_2_num;	  //���ֵڶ���ˮ���ĸ���
				++right;
			}
			else {
				//��һ��ˮ��δ����
				if (temp_1 == -1) {
					temp_1 = fruits[right++];
				}
				//��һ��ˮ�������˵��ǵڶ���ˮ��û����
				else if (temp_1 != -1 && temp_2 == -1) {
					temp_2 = fruits[right++];
				}
				//���ֵ�����ˮ��
				else {
					//whileѭ��ȷ��left��λ�ã������һ��ˮ��û�г����ˣ�����һ��ˮ���Ŀ�ͷλ�þ���left����ʼλ��
					while (temp_1_num && temp_2_num) {
						if (fruits[left] == temp_1) --temp_1_num;
						else --temp_2_num;
						++left;
					}

					//����ǵ�һ��ˮ������û���ˣ���ô���ǵڶ���ˮ���䵱��һ��ˮ��
					//��֮���ڶ���ˮ��û�������һ��ˮ�����������´εĻ��������ж�
					if (temp_1_num == 0) {
						temp_1 = temp_2;
						temp_1_num = temp_2_num;
					}
					
					//�����ֵĵ�����ˮ�����뻬�������еĵڶ���ˮ��
					temp_2 = fruits[right];
					temp_2_num = 0;
				}
			}
		}
		else ++right; //����������ڻ��������ڵ�����ˮ����ֱ������right

		max_len = max(max_len, right - left);
	}
	return max_len;
}

int main() {
	vector<int> fruits = { 1,0,1,4,1,4,1,2,3 };
	cout << totalFruit(fruits) << endl;
	return 0;
}