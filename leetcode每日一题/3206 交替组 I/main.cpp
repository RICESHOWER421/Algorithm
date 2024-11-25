#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int ans = 0, n = colors.size();
        for (int i = 1; i < n - 1; i++) ans += (colors[i] != colors[i + 1] && colors[i] != colors[i - 1]);
        return ans + (colors.back() != colors[n - 2] && colors.back() != colors[0]) + (colors[0] != colors[1] && colors[0] != colors.back());
    }
};

int main() {

	return 0;
}