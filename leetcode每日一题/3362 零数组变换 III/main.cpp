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
			while (cur < m && queries[cur][0] <= i) {	//�������ܸ��Ǹõ������ȫ������ 
				pq.push(queries[cur++][1]);
			}
			while (!pq.empty() && ret < nums[i] && pq.top() >= i) {	//ѡ�����Ҫѡ������䣬�������һ�����ȴӷ�Χ���Ŀ�ʼѡ 
				++ret;
				diff[pq.top() + 1]--;
				pq.pop();
			}
			if (ret < nums[i]) {	//������кϷ����䶼ѡ�귢�ֻ��Ǵﲻ��Ŀ�ģ����ʱ�޽� 
				return -1;
			}
		}
		//�����ѭ���ˣ�˵����ʱpq���������ֵ���ǿ��п��޵�ֵ 
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