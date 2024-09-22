#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> nums(n + 1);        //统计票数
        vector<int> vis(n + 1);         //统计是否投过票
        for (int i = 0; i < trust.size(); i++) {
            vis[trust[i][0]]++;
            nums[trust[i][1]]++;
        }

        for (int i = 1; i <= n; i++) {
            if (nums[i] == n - 1 && !vis[i]) return i;
        }
        return -1;
    }
};

int main() {

	return 0;
}