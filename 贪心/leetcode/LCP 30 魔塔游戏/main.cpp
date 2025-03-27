#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    int magicTower(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        ll sum = 1, ret = 0, cnt = 0;  
        for (auto& x : nums) {
            if (x < 0) {
                pq.push(x);
            }
            sum += x;
            while (!pq.empty() && sum <= 0) {
                sum += abs(pq.top());
                ret += pq.top();
                pq.pop();
                ++cnt;
            }
        }
        return sum >= abs(ret) ? cnt : -1;
    }
};

int main() {
    vector<int> nums = { 100,100,100,-250,-60,-140,-50,-50,100,150 };
    cout << Solution().magicTower(nums) << "\n";
 	return 0;
}