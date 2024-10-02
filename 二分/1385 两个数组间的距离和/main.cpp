#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int Binary_Search(int num, vector<int>& arr2, int find) {
        int left = 0, right = arr2.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (num - arr2[mid] < find) left = mid + 1;
            else right = mid;
        }
        return left;
    }

    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end(), greater<int>());

        int ans = 0;
        for (int i = 0; i < (int)arr1.size(); i++) {
            int left_index = Binary_Search(arr1[i], arr2, d + 1);
            int right_index = Binary_Search(arr1[i], arr2, -d);
            if (left_index == right_index) ++ans;
        }
        return ans;
    }
};

int main() {
    vector<int> arr1 = { 1,4,2,3 };
    vector<int> arr2 = { -4,-3,6,10,20,30 };
    int d = 3;
    cout << Solution().findTheDistanceValue(arr1, arr2, d) << endl;
	return 0;
}