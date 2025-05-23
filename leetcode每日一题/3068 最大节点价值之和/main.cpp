#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

class Solution {
public:
	using ll = long long;
	long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
		int n = nums.size();
		vector<vector<int>> e(n);
		for (auto& x : edges) {
			e[x[0]].push_back(x[1]);
			e[x[1]].push_back(x[0]);
		}

		auto dfs = [&](auto&& dfs, int cur, int ori)->pair<ll, ll> {	//����ֵ����ʾ������������y���ֵ���Ҳ��ʾ����ʱ����y�����ֵ 
			ll f0 = 0, f1 = LLONG_MIN;	//f[x][0]��ʾx����ż���κ�����x����x������ֵ�ͣ�f[x][1]��ʾx���������κ���������x������ֵ��	
			for (auto& x : e[cur]) {
				if (ori != x) {
					auto tmp = dfs(dfs, x, cur);
					//���������ڵ㶼û�в���
					ll ret = max(f0 + tmp.second, f1 + tmp.first);
					f0 = max(f0 + tmp.first, f1 + tmp.second);
					f1 = ret;
				}
			}
			return { max(f0 + nums[cur], f1 + (nums[cur] ^ k)), max(f1 + nums[cur], f0 + (nums[cur] ^ k)) };
		};
		return dfs(dfs, 0, -1).first;
	}
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	return 0;
}