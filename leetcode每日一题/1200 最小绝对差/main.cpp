#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int mn = abs(arr[0] - arr[1]), sz = arr.size();
        if (arr[0] < arr[1]) ans.push_back({ arr[0], arr[1] });
        else ans.push_back({ arr[1], arr[0] });
        for (int i = 2; i < sz; i++) {
            if (abs(arr[i] - arr[i - 1]) < mn) {
                mn = abs(arr[i] - arr[i - 1]);
                ans.clear();
                if (arr[i - 1] < arr[i]) ans.push_back({ arr[i - 1], arr[i] });
                else ans.push_back({ arr[i], arr[i - 1] });
            }
            else if (abs(arr[i] - arr[i - 1]) == mn) {
                if (arr[i - 1] < arr[i]) ans.push_back({ arr[i - 1], arr[i] });
                else ans.push_back({ arr[i], arr[i - 1] });
            }
        }
        return ans;
    }
};

int main() {

    return 0;
}