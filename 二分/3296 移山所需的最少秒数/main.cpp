#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

//n * (1 + n) / 2 * nums[i] = time;
//n * n + n - time / nums[i] * 2 = 0;
//二分答案
class Solution {
public:
    using ll = long long;
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        ll left = 1, right = 0;
        for (auto& x : workerTimes) {
            right = max(right, (ll)mountainHeight * (1 + (ll)mountainHeight) / 2 * (ll)x);
        }

        while (left < right) {
            ll mid = (left + right) / 2;
            ll sum = 0;
            for (auto& x : workerTimes) {
                ll ret = floor((sqrt(1 + 8 * mid / (ll)x) - 1) / 2.0);
                sum += ret;
            }

            if (sum >= mountainHeight) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};

//最小堆模拟
//struct cmp {
//    bool operator()(const pair<long long, pair<long long, long long>>& e1, const pair<long long, pair<long long, long long>>& e2){
//        return e1.first > e2.first;
//    }
//};
//class Solution {
//public:
//    using ll = long long;
//    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
//        priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll,ll>>>, cmp> pq;
//        for (auto& x : workerTimes) {
//            pq.push({ (ll)x, {(ll)x, 1}});
//        }
//
//        ll ans = 0;
//        while (mountainHeight--) {
//            pair<ll, pair<ll,int>> tmp = pq.top();
//            pq.pop();
//            ans = tmp.first;
//            pq.push({ tmp.first + tmp.second.first * (tmp.second.second + 1), {tmp.second.first,tmp.second.second + 1} });
//        }
//        return ans;
//    }
//};

int main() {
    int m = 4;
    vector<int> nums = {2,1,1};
    cout << Solution().minNumberOfSeconds(m, nums) << "\n";
    return 0;
}