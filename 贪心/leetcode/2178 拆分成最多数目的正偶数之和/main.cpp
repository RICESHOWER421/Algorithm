#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum % 2) return {};
        vector<long long> ans;
        long long begin = 2;
        while (finalSum) {
            if (finalSum - begin > begin || finalSum - begin == 0) {
                ans.push_back(begin);
                finalSum -= begin;
                begin += 2;
            }
            else {
                ans.push_back(finalSum);
                break;
            }
        }
        return ans;
    }
};

int main() {
    vector<long long> ans = Solution().maximumEvenSplit(28);
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
	return 0;
}