#include <iostream>
#include <map>
#include <vector>
typedef long long ll;
using namespace std;

//要给ll建议全部给ll，不然容易出现某个计算时int爆掉
void Test() {
	ll n = 0;
	cin >> n;

	map<ll, ll> hash_map;
	vector<ll> arr;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		if (!hash_map.count(num - i)) arr.push_back(num - i);
		hash_map[num - i]++;
	}

	ll ans = 0;
	for (int i = 0; i < (int)arr.size(); i++) {
		ans += hash_map[arr[i]] * (hash_map[arr[i]] - 1) / 2;
	}
	cout << ans << "\n";
}

int main() {
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}