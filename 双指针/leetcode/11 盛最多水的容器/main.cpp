#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maxArea(vector<int>& height) {
	int n = height.size();
	int left = 0, right = n - 1;
	int max_num = INT_MIN;
	while (left < right) {
		max_num = max(max_num, min(height[left], height[right]) * (right - left));
		if (height[left] < height[right]){
			++left;
		}
		else{
			--right;
		}
	}
	return max_num;
}

int main() {
	vector<int> height = { 1,5,6,1,3,9,100,100,4,8,3,7 };
	cout << maxArea(height) << endl;
	return 0;
}