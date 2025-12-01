/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int result = INT_MAX;
    TreeNode* pre = nullptr;
    void getMinimum(TreeNode* cur)
    {
        if(cur == nullptr) return;
        getMinimum(cur->left);
        if(pre)
        {
            result = min(result, (cur->val - pre->val) );
        }
        pre = cur;
        getMinimum(cur->right);
    }
    int getMinimumDifference(TreeNode* root) {
        getMinimum(root);
        return abs(result);
    }
};