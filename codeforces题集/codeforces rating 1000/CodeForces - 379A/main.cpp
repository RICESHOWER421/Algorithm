#include <iostream>
using namespace std;

void Test() {
	int a = 0, b = 0;
	cin >> a >> b;
	
	int ans = 0;
	int c = 0; //c是已经烧完的蜡烛
	while (a) {
		ans += a;		//计算烧的时间
		c += a;			//转换成已经烧完的蜡烛
		a = c / b;		//将已经烧完的蜡烛转换成新的蜡烛
		c = c % b;		//不能参与转换的烧完的蜡烛
	}
	cout << ans << endl;
}

int main() {
	Test();
	return 0;
}