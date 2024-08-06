#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//s是饼干，g是孩子
int findContentChildren(vector<int>& g, vector<int>& s) {
	sort(s.begin(), s.end());
	sort(g.begin(), g.end());

	int left = 0, right = 0, ans = 0;
	while (left < s.size() && right < g.size()) {
		if (s[left] >= g[right]) {
			++ans;
			++right;
		}
		++left;
	}
	return ans;
}

int main() {
	vector<int> g = { 1,2,3 };
	vector<int> s = { 1,2 };
	cout << findContentChildren(g, s) << endl;
	return 0;
}