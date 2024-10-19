#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
using namespace std;

void Test() {
    int n = 0, k = 0;
    cin >> n >> k;
    vector<double> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());
    double ans = -1;
    for (int i = 1; i < n; i++) {
        ans = max(ans, ((nums[i] - nums[i - 1]) / 2));
    }

    double num = max({ nums[0], ans, k - nums.back() });
    printf("%.10lf\n", num);
}

int main()
{
    Test();
    return 0;
}