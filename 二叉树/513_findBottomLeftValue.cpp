

/**
 * 给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。
 * 假设二叉树中至少有一个节点。
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
    int maxDepth = INT_MIN;   // 全局变量 记录最大深度
    int result;       // 全局变量 最大深度最左节点的数值
    void traversal(TreeNode* root, int depth)
    {
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr)
        {
            if(depth > maxDepth)
            {
                maxDepth = depth;
                result = root->val;
            }
            return;
        }
        if(root->left)
        {
            ++depth;
            traversal(root->left, depth);
            --depth;
        }
        if(root->right)
        {
            ++depth;
            traversal(root->right, depth);
            --depth;
        }
    }
    int findBottomLeftValue(TreeNode* root) {
        traversal(root, 1);
        return result;
    }
};