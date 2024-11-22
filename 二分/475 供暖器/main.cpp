#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int left = 0, right = max(houses.back(), heaters.back());
        while (left < right) {
            int mid = (left + right) / 2;
            int l = 0, r = 0;
            bool ok = true;
            while (l < houses.size() && r < heaters.size()) {
                if (houses[l] < heaters[r] - mid) {
                    ok = false;
                    break;
                }
                else if (houses[l] > heaters[r] + mid) ++r;
                else ++l;
            }
            if (l != houses.size()) ok = false;

            if (ok) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};

int main() {
    vector<int> h = { 1,5};
    vector<int> l = { 10 };
    cout << Solution().findRadius(h, l) << "\n";
	return 0;
}