#include <iostream>
#include <string>
#include <vector>
using namespace std;

string shiftingLetters(string s, vector<vector<int>>& shifts) {
    int n = s.size();
    vector<int> diff(n);

    for (int i = 0; i < shifts.size(); i++) {
        int left = shifts[i][0], right = shifts[i][1], x = shifts[i][2];
        diff[left] += (x == 0 ? -1 : 1);
        if (right + 1 < n) {
            diff[right + 1] -= (x == 0 ? -1 : 1);
        }
    }

    for (int i = 1; i < n; i++) {
        diff[i] += diff[i - 1];
    }

    for (int i = 0; i < n; i++) {
        int num = s[i] - 'a';
        if (diff[i] < 0) {
            diff[i] = 26 + (diff[i] % 26);
        }
        num = (num + diff[i]) % 26;
        s[i] = num + 'a';
    }
    return s;
}

int main() {
    string s = "abc";
    vector<vector<int>> shifts = { {0,1,0},{1,2,1},{0,2,1} };
    cout << shiftingLetters(s, shifts) << endl;
    return 0;
}