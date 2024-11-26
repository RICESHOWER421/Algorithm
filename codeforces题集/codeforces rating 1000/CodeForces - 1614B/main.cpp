#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
typedef long long ll;
using namespace std;

void Test() {
	int n = 0;
	cin >> n;

	vector<ll> ret, ans(n + 1);
	map<ll, vector<ll>> hash_map;
	for (int i = 0; i < n; i++) {
		int num = 0;
		cin >> num;
		if (!hash_map.count(num)) ret.push_back(num);
		hash_map[num].push_back(i + 1);
	}

	sort(ret.begin(), ret.end(), greater<ll>());
	ll sum = 0;
	int num = 1;
	bool ok = true;

	ans[0] = 0;
	for (int i = 0; i < ret.size(); i++) {
		for (int j = 0; j < hash_map[ret[i]].size(); j++) {
			sum += 2 * ret[i] * num;
			if (ok) {
				ans[hash_map[ret[i]][j]] = num;
				ok = false;
			}
			else {
				ans[hash_map[ret[i]][j]] = -num;
				++num;
				ok = true;
			}
		}
	}

	cout << sum << "\n";
	for (auto& x : ans) {
		cout << x << " ";
	}
	cout << "\n";
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}