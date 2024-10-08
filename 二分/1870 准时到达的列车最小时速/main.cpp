#include <iostream>
#include <vector>
using namespace std;

//x1 / ans + x2 / ans + x3 / ans + ... + xn / ans <= hour
class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if (hour <= n - 1) return -1;

        int left = 1, right = 10000000;
        while (left < right) {
            int mid = (left + right) / 2;
            double ans = 0;
            for (int i = 0; i < n; i++) {
                if (i != n - 1) ans += (dist[i] / mid + (dist[i] % mid != 0));
                else ans += ((double)dist[i] / mid);
            }
            if (ans <= hour) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};

int main() {
    vector<int> dist = { 1,3,2 };
    double hour = 2.7;
    cout << Solution().minSpeedOnTime(dist, hour) << endl;
	return 0;
}