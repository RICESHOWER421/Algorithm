#include <iostream>
#include <vector>
using namespace std;
int trap(vector<int>& height) {
	int left = 0, right = left;
	int sum = 0;
	while (right < height.size() - 1) {
		if (!height[left]) ++left;
		++right;
		if (height[right] < height[left]) sum += height[left] - height[right];
		if (left != right && height[right] >= height[left]) left = right;
	}
	
	//如果此时left正好在height数组边界，则不存在特殊值，直接返回结果
	if (left == height.size() - 1) return sum;
	else {
		int index = height.size() - 1;
		int temp = 0;
		while (index > left) {
			if (height[index] > temp) {
				temp = height[index];
			}
			sum -= (height[left] - temp);
			--index;
		}
	}
	return sum;
}

int main() {
	vector<int> height = { 4,2,0,3,2,5,10,0,8,0,9,0,0,5};
	cout << trap(height) << endl;
	return 0;
}