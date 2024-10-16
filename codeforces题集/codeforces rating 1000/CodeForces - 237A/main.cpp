#include <iostream>
#include <map>
#include <cmath>
using namespace std;

void Test() {
	int n = 0;
	cin >> n;

	map<pair<int, int>, int> hash_map;
	int ans = 0;
	while (n--) {
		int h = 0, m = 0;
		cin >> h >> m;
		hash_map[{h, m}]++;
		ans = max(hash_map[{h, m}], ans);
	}
	cout << ans << endl;
}
int main() {
	Test();
	return 0;
}