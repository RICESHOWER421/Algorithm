#include <iostream>
using namespace std;

class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if (abs(c - e) == abs(d - f)) {
            int n1 = e - c, n2 = f - d;
            for (int i = 1; i < abs(n1); i++) {
                if (c + i * (n1 > 0 ? 1 : -1) == a && d + i * (n2 > 0 ? 1 : -1) == b) {
                    return 2;
                }
            }
            return 1;
        }
        else if(a == e || b == f){
            if (a == e) {
                if (b < f) {
                    for (int i = 1; i < f - b; i++) {
                        if (b + i == d && a == c) {
                            return 2;
                        }
                    }
                    return 1;
                }
                else {
                    for (int i = 1; i < b - f; i++) {
                        if (b - i == d && a == c) {
                            return 2;
                        }
                    }
                    return 1;
                }
            }
            else {
                if (a < e) {
                    for (int i = 1; i < e - a; i++) {
                        if (a + i == c && b == d) {
                            return 2;
                        }
                    }
                    return 1;
                }
                else {
                    for (int i = 1; i < a - e; i++) {
                        if (a - i == c && b == d) {
                            return 2;
                        }
                    }
                    return 1;
                }
            }
        }
        else {
            return 2;
        }
    }
};

int main() {
    cout << Solution().minMovesToCaptureTheQueen(2, 2, 1, 1, 3, 3) << "\n";
	return 0;
}