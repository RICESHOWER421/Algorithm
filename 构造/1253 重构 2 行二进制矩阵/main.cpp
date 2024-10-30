#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int>> ans;
        int n = colsum.size();

        int ret_1 = upper, ret_2 = lower;
        vector<int> ans_1(n), ans_2(n);
        for (int i = 0; i < n; i++) {
            if (colsum[i] == 2) {
                if (ret_1 && ret_2) {
                    ans_1[i] = 1;
                    ans_2[i] = 1;
                    --ret_1;
                    --ret_2;
                }
                else {
                    return ans;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (colsum[i] == 1) {
                if (ret_1) {
                    ans_1[i] = 1;
                    --ret_1;
                }
                else if (ret_2) {
                    ans_2[i] = 1;
                    --ret_2;
                }
                else {
                    return ans;
                }
            }
        }

        if (ret_1 == 0 && ret_2 == 0) {
            ans.push_back(ans_1);
            ans.push_back(ans_2);
        }
        return ans;
    }
};

int main() {

	return 0;
}