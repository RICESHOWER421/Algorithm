#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode*left, TreeNode*right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool ok = true;
        auto dfs = [&](auto&& dfs, TreeNode* root)->int {
            if (root == nullptr || !ok) return 0;
            int left = dfs(dfs, root->left);
            int right = dfs(dfs, root->right);
            if (abs(right - left) > 1) ok = false;
            return max(left, right) + 1;
        };
        int num = dfs(dfs, root);
        return ok;
    }
};

int main() {

	return 0;
}