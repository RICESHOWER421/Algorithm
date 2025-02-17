#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int cnt = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[i - 1]) {
                ++cnt;
            }
            else {
                if (cnt > arr.size() / 4) {
                    return arr[i - 1];
                }
                cnt = 1;
            }
        }
        return -1;
    }
};

int main() {
    
    return 0;
}