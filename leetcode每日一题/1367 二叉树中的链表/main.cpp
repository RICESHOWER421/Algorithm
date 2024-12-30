#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isSubPath(ListNode* head, TreeNode* root)
    {
        auto dfs = [&](ListNode* h, TreeNode* r, auto&& self) -> bool
        {
            if (h == nullptr)
            {
                return true;
            }

            if (r == nullptr)
            {
                return false;
            }

            return h->val == r->val && (self(h->next, r->left, self) || self(h->next, r->right, self)) ||
                h == head && (self(head, r->left, self) || self(head, r->right, self));
        };
        return dfs(head, root, dfs);
    }
};


int main() {

    return 0;
}