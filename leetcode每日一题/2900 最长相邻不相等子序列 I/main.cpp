#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> r1, r2;
        int st1 = 1, st2 = 0;
        int l1 = 0, l2 = 0;
        for (int i = 0; i < groups.size(); i++) {
            if (st1 == groups[i]) {
                r1.push_back(words[i]);
                st1 = !st1;
                l1 += words[i].size();
            }
            else {
                if (!r1.empty() && words[i].size() > r1.back().size()) {
                    l1 = l1 - r1.back().size() + words[i].size();
                    r1.back() = words[i];
                }
            }

            if (st2 == groups[i]) {
                r2.push_back(words[i]);
                st2 = !st2;
                l2 += words[i].size();
            }
            else {
                if (!r2.empty() && words[i].size() > r2.back().size()) {
                    l2 = l2 - r2.back().size() + words[i].size();
                    r2.back() = words[i];
                }
            }
        }
        return l1 > l2 ? r1 : r2;
    }
};

int main() {

	return 0;
}