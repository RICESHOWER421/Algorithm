#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

//使用哈希表查找是否存在重复元素
//class Solution {
//public:
//    long long maximumTotalSum(vector<int>& maximumHeight) {
//        sort(maximumHeight.begin(), maximumHeight.end(), greater<int>());
//        
//        map<int, int> hash_map;
//        hash_map[maximumHeight[0]] = 1;
//        long long ans = maximumHeight[0];
//        for (int i = 1; i < (int)maximumHeight.size(); i++) {
//            if (hash_map.count(maximumHeight[i])) {
//                maximumHeight[i] = maximumHeight[i - 1] - 1;
//                if (maximumHeight[i] == 0) return -1;
//            }
//            hash_map[maximumHeight[i]] = 1;
//            ans += maximumHeight[i];
//        }
//        return ans;
//    }
//};

//方法二：直接使用min函数即可优化哈希
class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(maximumHeight.begin(), maximumHeight.end(), greater<int>());

        long long ans = maximumHeight[0];
        for (int i = 1; i < (int)maximumHeight.size(); i++) {
            maximumHeight[i] = min(maximumHeight[i], maximumHeight[i - 1] - 1);
            if (maximumHeight[i] == 0) return -1;
            ans += maximumHeight[i];
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {15,10};
    cout << Solution().maximumTotalSum(nums) << endl;
	return 0;
}