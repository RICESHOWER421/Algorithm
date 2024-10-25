#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int left = 0, right = 1;
        int mx = 0, mx_index = -1;
        int ret = 0;
        while (right < skills.size()) {
            if (skills[left] > skills[right]) {
                ++ret;
            }
            else {
                if (ret > mx) {
                    mx = ret;
                    mx_index = left;
                }
                if (mx >= k) {
                    return left;
                }
                left = right;
                ret = 1;
            }
            ++right;
        }
        if (ret > mx) {
            mx = ret;
            mx_index = left;
        }
        return left;
        
    }
};

int main() {

	return 0;
}