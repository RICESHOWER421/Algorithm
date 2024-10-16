#include <iostream>
#include <cstring>
#include <vector>
typedef long long ll;
using namespace std;

//欧拉筛写法
const int MAXN = 1e7;
bool isprime[MAXN]; 
int prime[MAXN]; 
int n = 1000000;
int cnt = 0; // 已经筛出的素数个数

void euler(){
	memset(isprime, true, sizeof(isprime));
	isprime[1] = false; 
	for (int i = 2; i <= n; ++i) 
	{
		if (isprime[i]) prime[++cnt] = i;
		for (int j = 1; j <= cnt && i * prime[j] <= n; ++j)	{
			isprime[i * prime[j]] = false;
			if (i % prime[j] == 0) break;
		}
	}
}


void Test() {
	int num = 0;
	cin >> num;
	
	ll ret_1 = 0, ret_2 = 0;
	for (int i = 0; i < cnt; i++) {
		if (prime[i] >= num + 1) {
			ret_1 = prime[i];
			break;
		}
	}

	for (int i = 0; i < cnt; i++) {
		if (prime[i] >= ret_1 + num) {
			ret_2 = prime[i];
			break;
		}
	}
	cout << ret_1 * ret_2 << endl;
}

int main() {
	euler();
	int test = 0;
	cin >> test;
	while (test--) {
		Test();
	}
	return 0;
}