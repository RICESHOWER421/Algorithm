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
    int n = 0;
    cin >> n;

    vector<string> str(n);
    map<string, int> hash_map;
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
        hash_map[str[i]]++;
    }

    for (int i = 0; i < str.size(); i++)
    {
        bool ok = true;
        for (int j = 0; j < str[i].size() - 1; j++)
        {
            string s1 = str[i].substr(0, j + 1);
            string s2 = str[i].substr(j + 1);
            if (hash_map.count(s1) && hash_map.count(s2))
            {
                cout << 1;
                ok = false;
                break;
            }
        }
        if (ok)
            cout << 0;
    }
    cout << "\n";
}


int main() {
    int test = 0;
    cin >> test;
    while (test--) {
        Test();
    }
    return 0;
}