#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
		vector<vector<int>> pts(numCourses, vector<int>());
		vector<int> cnts(numCourses);	//入度个数与权重大小 
		vector<vector<bool>> vis(numCourses, vector<bool>(numCourses));	//判断两点之间是否可达 
		vector<bool> ans;

		for (auto& x : prerequisites) {
			pts[x[0]].push_back(x[1]);
			cnts[x[1]]++;
		}

		queue<int> q;
		for (int i = 0; i < cnts.size(); i++) {
			if (!cnts[i]) {
				q.push(i);
			}
		}

		while (!q.empty()) {
			auto tmp = q.front();
			q.pop();

			for (auto& x : pts[tmp]) {
				cnts[x]--;
				vis[tmp][x] = true;
				for (int i = 0; i < numCourses; i++) {
					vis[i][x] = vis[i][tmp] || vis[i][x];
					// if(vis[i][x]){
					//     cout << i << "->" << x << "\n";
					// }
				}
				if (!cnts[x]) {
					q.push(x);
				}
			}
		}

		for (auto& x : queries) {
			ans.push_back(vis[x[0]][x[1]]);
		}
		return ans;
	}
};

int main() {
	int n = 2;
	vector<vector<int>> n1 = { {1,0} }, n2 = { {0,1},{1,0} };
	vector<bool> check = Solution().checkIfPrerequisite(n, n1, n2);
	for (int i = 0; i < n; i++) {
		cout << check[i] << " ";
	}
	cout << "\n";
	return 0;
}