#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void Test() {
	int n = 0, k = 0;
	cin >> n >> k;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	for (int i = 1; i <= n; i++) {
		int num = 0;
		cin >> num;
		pq.push({num, i});
	}

	int ret = 0;
	vector<int> ans;
	while (!pq.empty()) {
		pair<int, int> tmp = pq.top();
		pq.pop();
		if (k - tmp.first >= 0) {
			++ret;
			k -= tmp.first;
			ans.push_back(tmp.second);
		}
		else break;
	}

	cout << ret << "\n";
	for (auto& x : ans) cout << x << " ";
	cout << "\n";
}

int main() {
	Test();
	return 0;
}