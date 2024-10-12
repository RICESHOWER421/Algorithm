#include <iostream>
typedef long long ll;
using namespace std;

//细节问题，记得全部使用long long计算
int main() {
	ll n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	ll ans = ((n / k) + (n % k != 0)) * ((m / k) + (m % k != 0));
	cout << ans << endl;
	return 0;
}