#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int maxConsecutiveAnswers(string answerKey, int k) {
	int count_1 = 0, count_2 = 0;
	int left = 0, right = 0;
	int ret = 1;
	while (right < answerKey.size()) {
		if (count_1 <= k || count_2 <= k) {
			if (answerKey[right] == 'T' && (count_1 + 1 <= k || count_2 <= k)) ++count_1;
			else if (answerKey[right] == 'F' && (count_2 + 1 <= k || count_1 <= k)) ++count_2;
			else {
				if (answerKey[left] == 'T') --count_1;
				else --count_2;
				++left;
				continue;
			}
			ret = max(ret, count_1 + count_2);
			++right;
		}
	}
	return ret;
}

int main() {
	string answerKey = "TTFTTFTT";
	int k = 1;
	cout << maxConsecutiveAnswers(answerKey, k) << endl;
	return 0;
}