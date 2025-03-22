#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int pos = 0, cnt = -1;
        for (int i = 0; i < mat.size(); i++) {
            int a = 0;
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j]) {
                    ++a;
                }
            }
            if (a > cnt) {
                cnt = a;
                pos = i;
            }
        }
        return { pos, cnt };
    }
};

int main() {

	return 0;
}