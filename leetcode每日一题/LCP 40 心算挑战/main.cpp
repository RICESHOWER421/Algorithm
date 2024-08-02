#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int maxmiumScore(vector<int>& cards, int cnt) {
	sort(cards.begin(), cards.end());
	reverse(cards.begin(), cards.end());

	int sum = 0;
	int min1 = INT_MAX, min2 = INT_MAX;	//最小的奇数和最小的偶数
	for (int i = 0; i < cnt; i++) {
		sum += cards[i];
		if (cards[i] % 2) min1 = min(min1, cards[i]);
		else min2 = min2 = min(min2, cards[i]);
	}

	if (sum % 2 == 0) return sum;
	int max1 = INT_MIN, max2 = INT_MIN;	//最大的奇数和最大的偶数
	for (int i = cnt; i < cards.size(); i++) {
		if (cards[i] % 2) max1 = max(max1, cards[i]);
		else max2 = max(max2, cards[i]);
	}

	return max(0, max((max1 != INT_MIN && min2 != INT_MAX) ? sum - min2 + max1 : 0, (max2 != INT_MIN && min1 != INT_MAX ? sum - min1 + max2 : 0)));
}

int main() {
	vector<int> cards = {1,3,4,5};
	int cnt = 4;
	cout << maxmiumScore(cards, cnt) << endl;
	return 0;
}