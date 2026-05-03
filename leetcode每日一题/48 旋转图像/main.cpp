#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		/*
		*border为每次旋转的正方形的边界，比如一个3 * 3的方阵
		*第一次旋转的就是最外围的数据，也就是第三层的正方形
		*然后就是最里面的第二层正方形，以此类推
		*/
		int border = matrix.size() - 1;
		for (int i = 0; i < border; i++) {
			//sub存储偏差值，也就是在进行第二次和第三次旋转时所要临时存储的数的位置需要使用该偏差值
			int sub = 0;
			//逆时针旋转的四个数交换步骤，index + 1表示进行第几个数字旋转，temp存储需要交换的数据
			for (int j = i; j < border; j++) {
				if (j == border) break;	//如果最里面的正方形只有一个数据的话就可以不用旋转直接结束
				int index = 0;
				int temp_1 = -1, temp_2 = -1;
				while (index != 4) {
					if (index == 0) {
						temp_1 = matrix[j][border];
						matrix[j][border] = matrix[i][j];
						++index;
					}
					else if (index == 1) {
						temp_2 = matrix[border][border - sub];
						matrix[border][border - sub] = temp_1;
						temp_1 = temp_2;
						++index;
					}
					else if (index == 2) {
						temp_2 = matrix[border - sub][i];
						matrix[border - sub][i] = temp_1;
						temp_1 = temp_2;
						++index;
						++sub;
					}
					else {
						matrix[i][j] = temp_1;
						++index;
					}
				}
			}
			--border;	//每次外围正方形旋转完毕后继续旋转下一层正方形
		}
	}
};

int main() {

	return 0;
}