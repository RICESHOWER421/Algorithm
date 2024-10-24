#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
typedef long long ll;
using namespace std;

void Test()
{
    int n = 0, m = 0;
    cin >> n >> m;
    vector<pair<int, int>> arr1;
    vector<int> arr2;
    for (int i = 0; i < n; i++)
    {
        int num = 0;
        cin >> num;
        if (num % m == 0) {
            arr2.push_back(i + 1);
        }
        else {
            arr1.push_back({ num % m, i + 1 });
        }
    }

    sort(arr1.begin(), arr1.end(), [&](const pair<int, int>& a, const pair<int, int>& b)
        {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            else {
                return a.first > b.first;
            } });

    for (auto& x : arr2) {
        cout << x << " ";
    }
    for (auto& x : arr1) {
        cout << x.second << " ";
    }
    cout << "\n";
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