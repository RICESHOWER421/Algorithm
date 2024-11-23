#include <iostream>
#include <vector>
using namespace std;

//class Solution {
//public:
//    int hIndex(vector<int>& citations) {
//        int n = citations.size();
//        int left = 0, right = n;
//        while (left < right) {
//            int mid = left + (right - left + 1) / 2;
//            int count = 0;
//            for (auto& x : citations) {
//                if (x >= mid) ++count;
//            }
//
//            if (count >= mid) left = mid;
//            else right = mid - 1;
//        }
//        return left;
//    }
//};

//优化后写法
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;

            if (citations[n - mid] >= mid) left = mid;
            else right = mid - 1;
        }
        return left;
    }
};
int main() {
    vector<int> nums = {1,2};
    cout << Solution().hIndex(nums) << "\n";
	return 0;
}