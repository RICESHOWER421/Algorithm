#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for (auto& x : queries) {
            int n = x.size();
            for (auto& y : dictionary) {
                bool ok = true;
                int cnt = 0;
                for (int i = 0; i < n; i++) {
                    cnt += (x[i] != y[i]);
                    if (cnt > 2) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    ans.push_back(x);
                    break;
                }
            }
        }
        return ans;
    }
};

int main() {

	return 0;
}