#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

void Test() {
    int n = 0;
    cin >> n;
    vector<int> nums;
    map<int, int> hash_map;
    for (int i = 0; i < n; i++) {
        int num = 0;
        cin >> num;
        if (!hash_map.count(num)) {
            nums.push_back(num);
        }
        hash_map[num]++;
    }

    int mx = -1;
    for (int i = 0; i < (int)nums.size(); i++) {
        mx = max(mx, hash_map[nums[i]]);
    }

    if (mx > nums.size() - 1) {
        if (mx == nums.size()) {
            cout << nums.size() - 1 << "\n";
        }
        else {
            cout << nums.size() << "\n";
        }
    }
    else {
        cout << mx << "\n";
    }
}


int main()
{
    int test = 0;
    cin >> test;
    while (test--)
    {
        Test();
    }
    return 0;
}