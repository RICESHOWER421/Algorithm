#include <bits/stdc++.h>
using namespace std;


struct TreeNode {   
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
    vector<int> nums;
public:
    TreeNode* DFS(int left, int right) {
        if (left == right) return nullptr;
        int cur = left + (right - left) / 2;
        return new TreeNode(nums[cur], DFS(left, cur), DFS(cur + 1, right));
    }
    TreeNode* balanceBST(TreeNode* root) {
        //中序排序获取有序数列
        auto dfs = [&](auto&& dfs, TreeNode* root)->void {
            if (root == nullptr) return;
            dfs(dfs, root->left);
            nums.push_back(root->val);
            dfs(dfs, root->right);
        };
        dfs(dfs, root);

        //有序数列构造二叉平衡树（二叉搜索树）
        return DFS(0,nums.size());
    }
};
int main() {

	return 0;
}