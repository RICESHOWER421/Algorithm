#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
 
//�ö�ģ��ᳬʱ����Ҫ�Ż�
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long ans = 0;
        vector<int> nums;
        for (int i = 0; i < (int)nums1.size(); i++) {
            if(abs(nums1[i] - nums2[i])) nums.push_back(abs(nums1[i] - nums2[i]));
        }
        nums.push_back(0);

        sort(nums.begin(), nums.end(), greater<int>());
        int k = k1 + k2;
        int cur = 0, ret = nums[0];
        int more = 0;
        while (cur < (int)nums.size() && k) {
            if (nums[cur] != ret) {
                int sum = cur * (ret - nums[cur]);
                if (k > sum) {
                    k -= sum;
                    ret = nums[cur];
                }
                else break;
            }
            ++cur;
        }

        if(cur != (int)nums.size()) {
            for (int i = cur; i < (int)nums.size(); i++) {
                ans += (long long)nums[i] * nums[i];
            }
            
            if (cur) {
                long long num_1 = k / cur;    //ÿ���������ܼ�ȥ����
                long long num_2 = k % cur;    //ʣ�µ�k���ܸ�����������
                ans += (num_2 * (pow(ret - (num_1 + 1),2)) + (cur - num_2) * (pow(ret - num_1, 2)));
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums1 = { 1,4,10,12 };
    vector<int> nums2 = { 5,8,6,9 };
    int k1 = 1;
    int k2 = 1;
    cout << Solution().minSumSquareDiff(nums1, nums2, k1, k2) << endl;
	return 0;
}