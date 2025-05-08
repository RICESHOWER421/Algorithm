#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		vector<vector<int>> pts(n, vector<int>());
		vector<int> cnts(n);	//计算度数
		for (auto& x : edges) {
			pts[x[0]].push_back(x[1]);
			pts[x[1]].push_back(x[0]);
			cnts[x[0]]++;
			cnts[x[1]]++;
		}

		queue<int> q;
		for (int i = 0; i < n; i++) {
			if (cnts[i] == 1) {
				q.push(i);
			}
		}

		int remain = n;		//剩下多少个点没有访问，如果剩下两个或者一个则直接出最小高度树
		while (remain > 2) {
			int sz = q.size();
			remain -= sz;
			while (sz--) {
				int pos = q.front();
				q.pop();

				for (auto& x : pts[pos]) {
					cnts[x]--;
					if (cnts[x] == 1) {
						q.push(x);
					}
				}
			}
		}

		vector<int> ans;
		while (!q.empty()) {
			ans.push_back(q.front());
			q.pop();
		}
		return ans;
	}
};

int main() {
	vector<vector<int>> edges = { {1,0}, {1,2}, {1,3} };
	vector<int> ans = Solution().findMinHeightTrees(4, edges);
	for (auto& x : ans) {
		cout << x << " ";
	}
	cout << "\n";
	return 0;
}