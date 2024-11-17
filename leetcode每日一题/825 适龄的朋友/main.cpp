#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

//ages[y] > 0.5 * ages[x] + 7
//ages[y] <= ages[x]
//ages[y] <= 100 || ages[x] >= 100

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        map<int, int> hash_map;
        vector<int> ret;
        for (auto& x : ages) {
            if (!hash_map.count(x)) {
                ret.push_back(x);
            }
            hash_map[x]++;
        }

        sort(ret.begin(), ret.end(), greater<int>());
        vector<int> dp(ret.size() + 1);
        for (int i = 1; i <= ret.size(); i++) {
            dp[i] = dp[i - 1] + hash_map[ret[i - 1]];
        }

        int ans = 0;
        for (int i = 0; i < ret.size(); i++) {
            int left = i + 1, right = ret.size();
            while (left < right) {
                int mid = (left + right) / 2;
                if (ret[i] * 0.5 + 7 < ret[mid]) left = mid + 1;
                else right = mid;
            }
            if (ret[i] > 14) ans += hash_map[ret[i]] * (hash_map[ret[i]] - 1);
            ans += hash_map[ret[i]] * (dp[left] - dp[i + 1]);
        }
        return ans;
    }
};

int main() {
    vector<int> ages = { 1,1,2,2,3,4,5,6,7,8,9,10,100,101,102,110 };
    cout << Solution().numFriendRequests(ages) << "\n";
	return 0; 
}