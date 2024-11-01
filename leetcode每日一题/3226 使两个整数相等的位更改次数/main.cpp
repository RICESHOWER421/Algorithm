#include <iostream>
using namespace std;

class Solution {
public:
    int minChanges(int n, int k) {
        int ret = 0;
        while (n || k) {
            if (n % 2 && k % 2 == 0) ++ret;
            else if (n % 2 == 0 && k % 2) return -1;
            n /= 2;
            k /= 2;
        }
        return ret;
    }
};

int main() {
    cout << Solution().minChanges(13, 4) << "\n";
	return 0;
}