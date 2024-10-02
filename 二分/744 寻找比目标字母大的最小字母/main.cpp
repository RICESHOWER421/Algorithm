#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	char nextGreatestLetter(vector<char>& letters, char target) {
		if (target == 'z') return letters[0];

		int left = 0, right = (int)letters.size() - 1;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (letters[mid] <= target) left = mid + 1;
			else right = mid;
		}
		return letters[left] <= target ? letters[0] : letters[left];
	}
};

int main() {

	return 0;
}