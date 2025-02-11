#include <iostream>
#include <cmath>
#include <cstring>
typedef long long ll;
using namespace std;

bool isprime[1000001];
int prime[1000001];
int ret = 1000000; 
int cnt;

void euler()
{
    memset(isprime, true, sizeof(isprime)); 
    isprime[1] = false; 
    for (int i = 2; i <= ret; ++i) 
    {
        if (isprime[i]) prime[++cnt] = i;
        for (int j = 1; j <= cnt && i * prime[j] <= ret; ++j)
        {
			isprime[i * prime[j]] = false;
            if (i % prime[j] == 0) break;
        }
    }
}

void Test() {
	int n = 0;
	cin >> n;
	while (n--) {
		ll num = 0;
		cin >> num;
		if (num <= 3) {
			cout << "NO" << "\n";
		} 
		else {
			ll tmp = (ll)sqrt(num);
			if (tmp * tmp == num && isprime[tmp]) cout << "YES" << "\n";
			else cout << "NO" << "\n";
		}
	} 
}

int main() {
	euler();
	Test();
	return 0;
}