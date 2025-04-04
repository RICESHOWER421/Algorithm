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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int mx = -1;
        TreeNode* ans = nullptr;
        auto dfs = [&](auto&& dfs, TreeNode* root, int pos) -> int {
            if (root == nullptr) {
                return -1;
            }

            int left = dfs(dfs, root->left, pos + 1);
            int right = dfs(dfs, root->right, pos + 1);
            if (left == right) {
                if (left == -1 || right == -1) {
                    if (pos > mx) {
                        mx = pos;
                        ans = root;
                    }
                    return pos;
                }
                else {
                    if (left == mx) {
                        ans = root;
                    }
                    return left;
                }
            }
            else {
                return max(left, right);
            }
        };

        int ret = dfs(dfs, root, 0);
        return ans;
    }
};

int main() {
    TreeNode* c1 = new TreeNode(0);
    TreeNode* c2 = new TreeNode(1);
    TreeNode* c3 = new TreeNode(3);
    TreeNode* c4 = new TreeNode(2);
    c1->left = c2;
    c1->right = c3;
    c2->left = nullptr;
    c2->right = c4;
    cout << Solution().lcaDeepestLeaves(c1)->val << "\n";
	return 0;
}