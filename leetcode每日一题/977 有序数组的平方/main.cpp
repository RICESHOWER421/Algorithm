#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    vector<int> ret;
    for (auto& x : nums) ret.push_back(x * x);
    sort(ret.begin(), ret.end());
    return ret;
}

int main() {

	return 0;
}