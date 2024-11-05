#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int mx = 0;
        for (auto& x : left) {
            mx = max(mx, x);
        }
        for (auto& x : right) {
            mx = max(mx, n - x);
        }
        return mx;
    }
};

int main() {

	return 0;
}