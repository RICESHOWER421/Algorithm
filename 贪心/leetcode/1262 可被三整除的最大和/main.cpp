#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

//һ��ʼ�����̰�Ĳ����ǣ�����������Ϊ3�࣬һ��ģ����0��һ����ģ����һ��һ��ģ�������Ȼ������������������Ȼ�������Ӻ���ǰ���б����������������ڵ�һ�࣬��ô�����һ�����Լ��ϣ�����ǵڶ��������࣬��ô����Ҫ����ƥ�����������ֵ��������̰���Ǵ���ģ�������˵���ʮ����������𰸲���3���о���ƥ�������ֵ���������⣬����һʱ�����Ҳû�뵽�õİ취�������������ŵ�̰�ġ�
//���ŵ�̰���ǣ�����������������ĺͣ����������ܱ�3��������ôֱ�ӷ��ظý�����У������3��������������ô�����������������
//1������Ϊ1����ʱҪô�Ƕ���һ�����������ģ3��1����ȥ������ܺ;��ܱ��������ˣ���ʱ���ŵĲ��Ծ��Ǽ�ȥ��С���ܹ�ģ3��1������Ҫô�Ƕ�����������������������ģ3��2�ģ���ȥ��������ͬ��Ҳ�ܱ�3��������ô��ʱ���ŵĲ��Ծ��Ǽ�ȥ��С�ĺʹ�С���ܹ�ģ3��2��������������ȡ������������Ž⼴��
//2������Ϊ2��������ͬ��Ҫô����һ��ģ3��2������Ҫô��������ģ3��1���������Ų���ͬ������һ�����һ�������ȡ����������Ž⼴�ɡ�
//��������ֻ��Ҫһ��ѭ���������ֱ������������Ԫ�صĺ��Լ�ģ3��1��ģ3��2����Сֵ�ʹ�Сֵ�������ĿҲ�������
int maxSumDivThree(vector<int>& nums) {
	int ans = 0;
	int min_num_1_1 = INT_MAX, min_num_1_2 = INT_MAX;
	int min_num_2_1 = INT_MAX, min_num_2_2 = INT_MAX;
	for (int i = 0; i < nums.size(); i++) {
		ans += nums[i];
        if (nums[i] % 3 == 1) {
            if (nums[i] < min_num_1_2) {
                if (nums[i] < min_num_1_1) {
                    min_num_1_2 = min_num_1_1;
                    min_num_1_1 = nums[i];
                }
                else min_num_1_2 = nums[i];
            }
        }
        if (nums[i] % 3 == 2) {
            if (nums[i] < min_num_2_2) {
                if (nums[i] < min_num_2_1) {
                    min_num_2_2 = min_num_2_1;
                    min_num_2_1 = nums[i];
                }
                else min_num_2_2 = nums[i];
            }
        }
	}
	if (ans % 3 == 0) return ans;
    else {
        if (ans % 3 == 1) {
            int num1 = ans - min_num_1_1;
            int num2 = min_num_2_2 == INT_MAX ? 0 : ans - min_num_2_1 - min_num_2_2;
            return max(num1, num2);
        }
        else {
            int num1 = ans - min_num_2_1;
            int num2 = min_num_1_2 == INT_MAX ? 0 : ans - min_num_1_1 - min_num_1_2;
            return max(num1, num2);
        }
    }
}

int main() {
	vector<int> nums = {1,2,2,2,2,2};
	cout << maxSumDivThree(nums) << endl;
	return 0;
}