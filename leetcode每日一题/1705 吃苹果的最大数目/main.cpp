#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct cmp {
        bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        }
    };
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int ans = 0, n = apples.size(), day = 1;

        vector<pair<int, int>> nums;
        for (int i = 0; i < n; i++) {
            nums.push_back({apples[i], i + 1 + days[i]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for (int i = 0; i < n || !pq.empty(); i++) {
            //每天添加该有的苹果
            if (i < n && nums[i].first) {
                pq.push(nums[i]);
            }

            //在开始吃苹果前先处理腐烂的苹果
            while (!pq.empty() && (pq.top().second <= day)) {    
                pq.pop();
            }
            
            //正式开始吃苹果
            if (!pq.empty()) {
                pair<int, int> tmp = pq.top();
                pq.pop();
                ++ans;
                if (tmp.first - 1) {
                    pq.push({ tmp.first - 1, tmp.second });
                }
            }
            ++day;  //不管吃没吃到苹果，天数都需要+1
        }
        return ans;
    }
};

int main() {
    vector<int> apples = { 1,2,3,5,2 }, days = { 3,2,1,4,2 };
    cout << Solution().eatenApples(apples, days) << "\n";
    return 0;
}