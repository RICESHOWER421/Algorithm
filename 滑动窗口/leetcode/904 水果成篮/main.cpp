#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int totalFruit(vector<int>& fruits) {
	int n = fruits.size();
	int temp_1 = -1, temp_2 = -1;  //两种不同的水果类型
	int temp_1_num = 1, temp_2_num = 1;  //两种不同水果类型的个数
	int left = 0, right = 0, max_len = -1;
	while (right <= n - 1) {
		//关键点，最难分析的一个环节，即left在滑动窗口中的位置在哪里
		if (fruits[right] != temp_1 || fruits[right] != temp_2) { //如果出现了这两种类型以外的其它水果
			if (fruits[right] == temp_1 || fruits[right] == temp_2) {
				if (fruits[right] == temp_1) ++temp_1_num;    //出现第一种水果的个数
				if (fruits[right] == temp_2) ++temp_2_num;	  //出现第二种水果的个数
				++right;
			}
			else {
				//第一种水果未出现
				if (temp_1 == -1) {
					temp_1 = fruits[right++];
				}
				//第一种水果出现了但是第二种水果没出现
				else if (temp_1 != -1 && temp_2 == -1) {
					temp_2 = fruits[right++];
				}
				//出现第三种水果
				else {
					//while循环确定left的位置，如果有一种水果没有出现了，则另一种水果的开头位置就是left的起始位置
					while (temp_1_num && temp_2_num) {
						if (fruits[left] == temp_1) --temp_1_num;
						else --temp_2_num;
						++left;
					}

					//如果是第一种水果正好没有了，那么就是第二种水果充当第一种水果
					//反之，第二种水果没有了则第一种水果继续进入下次的滑动窗口判断
					if (temp_1_num == 0) {
						temp_1 = temp_2;
						temp_1_num = temp_2_num;
					}
					
					//将出现的第三种水果列入滑动窗口中的第二种水果
					temp_2 = fruits[right];
					temp_2_num = 0;
				}
			}
		}
		else ++right; //如果出现了在滑动窗口内的两种水果则直接右移right

		max_len = max(max_len, right - left);
	}
	return max_len;
}

int main() {
	vector<int> fruits = { 1,0,1,4,1,4,1,2,3 };
	cout << totalFruit(fruits) << endl;
	return 0;
}