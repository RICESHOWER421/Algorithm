#include <iostream>
#include <cmath>
using namespace std;

//dfs����
//int path = 0;
//int ret = INT_MAX;
//void dfs(int n) {
//	if (n == 1) {
//		ret = min(ret, path);
//		return;
//	}
//
//	if (!(n % 2)) {
//		++path;
//		dfs(n / 2);
//		--path;		//����
//	}
//	else {
//		++path;
//		dfs(n + 1);
//		--path;		//����
//
//		++path;
//		dfs(n - 1);
//		--path;		//����
//	}
//}
//
//int integerReplacement(int n) {
//	dfs(n);
//	return ret;
//}

//̰�ģ�˵ʵ�����̰���е��������
int integerReplacement(int n) {
    int ans = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            ++ans;
            n /= 2;
        }
        else if (n % 4 == 1) {
            ans += 2;
            n /= 2;
        }
        else {
            if (n == 3) {
                ans += 2;
                n = 1;
            }
            else {
                ans += 2;
                n = n / 2 + 1;
            }
        }
    }
    return ans;
}

int main() {
	cout << integerReplacement(98237) << endl;
	return 0;
}