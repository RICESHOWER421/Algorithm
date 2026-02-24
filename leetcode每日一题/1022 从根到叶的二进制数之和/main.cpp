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
public:
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        string s;
        auto dfs = [&](auto&& dfs, TreeNode* root)->void {
            s += (root->val + '0');
            if (root->left == nullptr && root->right == nullptr) {
                int cur = s.size() - 1, cnt = 0;
                while (cur >= 0) {
                    ans += (s[cur--] - '0') * pow(2, cnt++);
                }
            }

            if (root->left != nullptr) dfs(dfs, root->left);
            if (root->right != nullptr) dfs(dfs, root->right);
            s.pop_back();
        };
        dfs(dfs, root);
        return ans;
    }
};

int main() {
    TreeNode* t1 = new TreeNode(1), *t3 = new TreeNode(1), *t5 = new TreeNode(1), *t7 = new TreeNode(1), *t2 = new TreeNode(), * t4 = new TreeNode(), * t6 = new TreeNode();
    t1->left = t2, t1->right = t3, t2->left = t4, t2->right = t5, t3->left = t6, t3->right = t7;
    cout << Solution().sumRootToLeaf(t1);
	return 0;
}