#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        for (int i = arr.size(); i >= 1; i--) {
            for (int j = 0; j < arr.size(); j++) {
                if (i == arr[j]) {
                    if(i != j + 1){
                        if (j != 0) {
                            ans.push_back(j + 1);
                            reverse(arr.begin(), arr.begin() + j + 1);
                        }
                        ans.push_back(arr.size() - (arr.size() - i));
                        reverse(arr.begin(), arr.end() - (arr.size() - i));
                    }
                    break;
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> arr = {3,2,4,1};
    vector<int> ans = Solution().pancakeSort(arr);
    for (auto& x : ans) {
        cout << x << " ";
    }
    cout << "\n";
	return 0;
}