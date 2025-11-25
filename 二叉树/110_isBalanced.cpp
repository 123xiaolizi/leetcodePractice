//给定一个二叉树，判断它是否是 平衡二叉树  

/**
 * Definition for a binary tree node.
 */
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
    int getHigh(TreeNode* node)
    {
        if(node == nullptr) return 0;
        int left_high = getHigh(node->left);
        int right_high = getHigh(node->right);
        if(left_high == -1 || right_high == -1) return -1;
        if(abs(left_high - right_high) > 1) return -1;
        return 1+ max(left_high, right_high);
    }
    bool isBalanced(TreeNode* root) {
        if(getHigh(root) == -1) return false;
        return true;
    }
};