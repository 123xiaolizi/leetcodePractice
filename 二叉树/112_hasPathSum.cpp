
/*
给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。
判断该树中是否存在 根节点到叶子节点 的路径，
这条路径上所有节点值相加等于目标和 targetSum 。
如果存在，返回 true ；否则，返回 false 。
*/
bool hasPathSum(TreeNode *root, int targetSum)
{
    if (root == nullptr)
        return false;
    if (root->left == nullptr && root->right == nullptr)
    {
        if (targetSum - root->val == 0)
        {
            return true;
        }
        return false;
    }
    targetSum = targetSum - root->val;
    if (root->left)
    {
        if (hasPathSum(root->left, targetSum))
            return true;
    }
    if (root->right)
    {
        if (hasPathSum(root->right, targetSum))
            return true;
    }
    targetSum += root->val;
    return false;
}