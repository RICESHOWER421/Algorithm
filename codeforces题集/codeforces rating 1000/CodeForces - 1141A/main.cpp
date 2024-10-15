#include <iostream>
using namespace std;

int ret = 0;
bool ok = false;
int ans = ret;
void dfs(int a, int b) {
	if (b == a) {
		ok = true;
		ans = ret;
		return;
	}
	else if (b < a) return;
	
	if (!ok && b % 2 == 0) {	//注意一定要能整除才能进行递归
		++ret;
		dfs(a, b / 2);
		--ret;
	}

	if (!ok && b % 3 == 0) {
		++ret;
		dfs(a, b / 3);
		--ret;
	}
}

void Test() {
	int a = 0, b = 0;
	cin >> a >> b;
	dfs(a, b);
	cout << (ok ? ans : -1) << endl;
}

int main() {
	Test();
	return 0;
}