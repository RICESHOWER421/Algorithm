#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        unordered_map<int, int> hash_map;   //存储机器人实际血量
        vector<int> idx, new_pos;
        for (int i = 0; i < n; i++) {
            new_pos.push_back(i);
        }
        sort(new_pos.begin(), new_pos.end(), [&](const int a, const int b) { //确认实际顺序
            return positions[a] < positions[b];
            });

        for (int i = 0; i < n; i++) {
            if (directions[new_pos[i]] == 'R') {
                hash_map[new_pos[i]] = healths[new_pos[i]];
                idx.push_back(new_pos[i]);
            }
            else {
                int hp = healths[new_pos[i]];
                while (hp && !hash_map.empty() && directions[idx.back()] != 'L') {
                    if (hp > hash_map[idx.back()]) {    //如果往左走的机器人血量更多，那么血量-1，移除最后一个向右走的机器人
                        --hp;
                        hash_map.erase(idx.back());
                        idx.pop_back();
                    }
                    else if (hp < hash_map[idx.back()]) {   //如果往右走的机器人血量更多，那么往左走的机器人移除
                        hash_map[idx.back()] -= 1;
                        hp = 0;
                    }
                    else {   //如果血量相同，两个直接都删除
                        hash_map.erase(idx.back());
                        idx.pop_back();
                        hp = 0;
                    }
                }
                if ((hash_map.empty() || directions[idx.back()] == 'L') && hp) {  //如果没有机器人存活而且该机器人还有血量
                    hash_map[new_pos[i]] = hp;
                    idx.push_back(new_pos[i]);
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (hash_map.find(i) != hash_map.end()) {
                ans.push_back(hash_map[i]);
            }
        }
        return ans;
    }
};

int main() {

	return 0;
}