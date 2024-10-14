#include <iostream>
#include <queue>
using namespace std;

void Test() {
	int n = 0, m = 0;
	cin >> n >> m;

	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		int num = 0;
		cin >> num;
		q.push({i + 1, num});
	}

	while (q.size() > 1) {
		pair<int, int> temp = q.front();
		q.pop();
		if (temp.second > m) q.push({temp.first, temp.second - m});
	}
	cout << q.front().first << endl;
}

int main() {
	Test();
	return 0;
}