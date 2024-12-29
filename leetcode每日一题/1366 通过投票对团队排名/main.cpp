#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        vector<vector<int>> nums(26, vector<int>(26));
        vector<int> index;
        for (int i = 0; i < 26; i++) {
            index.push_back(i);
        }

        for (auto& x : votes) {
            for (int i = 0; i < x.size(); i++) {
                nums[x[i] - 'A'][i]++;
            }
        }

        sort(index.begin(), index.end(), [&](const int& a, const int& b) {
            for (int i = 0; i < 26; i++) {
                if (nums[a][i] != nums[b][i]) {
                    return nums[a][i] > nums[b][i];
                }
            }
            return a < b;
        });

        string ans;
        for (int i = 0; i < votes[0].size(); i++) {
            ans += (index[i] + 'A');
        }
        return ans;
    }
};

int main() {
    vector<string> votes = { "ABC","ACB","ABC","ACB","ACB" };
    cout << Solution().rankTeams(votes) << "\n";
	return 0;
}
