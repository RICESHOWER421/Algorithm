#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int func(int a, int b) {
        int ans = 1;
        bool index = false;
        while (1) {
            if (!index) {
                if (a >= ans)  a -= ans;           
                else break;
            }
            else {
                if (b >= ans) b -= ans;
                else break;
            }
            index = !index;
            ++ans;
        }
        return ans - 1;
    }

    int maxHeightOfTriangle(int red, int blue) {
        int ans_1 = func(red, blue), ans_2 = func(blue, red);
        return max(ans_1, ans_2);
    }
};

int main() {

	return 0;
}