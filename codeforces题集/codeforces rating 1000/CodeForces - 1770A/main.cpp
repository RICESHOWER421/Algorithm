#include <iostream>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;

void Test() {
	int n = 0, m = 0;
	cin >> n >> m;
	
	ll sum = 0;
	priority_queue<ll, vector<ll>, greater <ll>> pq;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		sum += num;
		pq.push(num);
	}

	for (int i = 0; i < m; i++) {
		ll num = 0;
		cin >> num;
		sum = sum + num - pq.top();
		pq.pop();
		pq.push(num);
	}
	cout << sum << "\n";
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}