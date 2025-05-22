#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

class Solution {
public:
	int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
		sort(queries.begin(), queries.end());
		int n = nums.size(), m = queries.size(), ret = 0;
		vector<int> diff(n + 1);
		priority_queue<int> pq;
		int cur = 0;
		for (int i = 0; i < n; i++) {
			ret += diff[i];
			while (cur < m && queries[cur][0] <= i) {	//将所有能覆盖该点的区间全部加入 
				pq.push(queries[cur++][1]);
			}
			while (!pq.empty() && ret < nums[i] && pq.top() >= i) {	//选择必须要选择的区间，这个区间一定是先从范围最大的开始选 
				++ret;
				diff[pq.top() + 1]--;
				pq.pop();
			}
			if (ret < nums[i]) {	//如果所有合法区间都选完发现还是达不到目的，则此时无解 
				return -1;
			}
		}
		//如果出循环了，说明此时pq里面的区间值都是可有可无的值 
		return pq.size();
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test = 0;
	cin >> test;

	return 0;
}