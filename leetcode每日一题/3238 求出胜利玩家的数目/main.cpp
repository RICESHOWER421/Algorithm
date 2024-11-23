#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<vector<int>> hash_map(10, vector<int>(11));
        vector<bool> vis(10);
        int count = 0;
        for (int i = 0; i < pick.size(); i++) {
            hash_map[pick[i][0]][pick[i][1]]++;
            if (hash_map[pick[i][0]][pick[i][1]] > pick[i][0] && !vis[pick[i][0]]) {
                vis[pick[i][0]] = true;
                ++count;
            }
        }
        return count;
    }
};

int main() {

	return 0;
}