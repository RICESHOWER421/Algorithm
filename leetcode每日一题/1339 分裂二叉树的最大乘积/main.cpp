#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

using ll = long long;
const int MOD = 1e9 + 7;
class Solution {
public:
    int maxProduct(TreeNode* root) {
        unordered_map<TreeNode*, pair<int, int>> hash_map;
        int sum = 0;
        auto dfs1 = [&](auto&& dfs1, TreeNode* root)->int {   //后序遍历依次求出每个节点的左右子树总和
            if (root == nullptr) return 0;
            int l = dfs1(dfs1, root->left);
            hash_map[root].first = l;
            int r = dfs1(dfs1, root->right);
            hash_map[root].second = r;
            sum += root->val;
            return l + r + root->val;
        };
        dfs1(dfs1,root);

        ll ans = -1;
        for (auto& x : hash_map) {
            ans = max(ans, max((ll)x.second.second * (sum - x.second.second), (ll)x.second.first * (sum - x.second.first)));
        }
        return ans % MOD;
    }
};

int main() {

	return 0;
}