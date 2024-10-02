#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int Binary_Search(int num, vector<int>& potions, long long find) {
        int left = 0, right = potions.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if ((long long)num * potions[mid] < find) left = mid + 1;
            else right = mid;
        }
        return left;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        
        vector<int> ans;
        for (int i = 0; i < (int)spells.size(); i++) {
            ans.push_back((int)potions.size() - Binary_Search(spells[i], potions, success));
        }
        return ans;
    }
};

int main() {

	return 0;
}