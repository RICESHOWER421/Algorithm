#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(), score.end(), [&](const vector<int>& a, vector<int>& b) {
            return a[k] > b[k];
            });
        return score;
    }
};

int main() {

	return 0;
}