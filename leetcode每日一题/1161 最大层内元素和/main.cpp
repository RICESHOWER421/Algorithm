#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    const int MIN = -(1e9 + 10);
    int maxLevelSum(TreeNode* root) {
        vector<int> hash_map(1e4 + 1, MIN);
        auto dfs = [&](auto&& dfs, TreeNode* node, int floor)->void {
            if (node == nullptr) return;
            if (hash_map[floor] == MIN) hash_map[floor] = 0;
            hash_map[floor] += node->val;
            dfs(dfs, node->left, floor + 1);
            dfs(dfs, node->right, floor + 1);
        };
        dfs(dfs, root, 1);
        int num = MIN, ans = 1;
        for (int i = 1; i <= 1e4; i++) {
            if (hash_map[i] > num) {
                ans = i;
                num = hash_map[i];
            }
        }
        return ans;
    }
};

int main() {

	return 0;
}