

//给定二叉树的根节点 root ，返回所有左叶子之和。
int sumOfLeftLeaves(TreeNode* root) 
{
    if(root == nullptr) return 0;
    if(root->left == nullptr && root->right == nullptr) return 0;
    int leftval = sumOfLeftLeaves(root->left);
    if(root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
    {
        leftval = root->left->val;
    }
    int rightval = sumOfLeftLeaves(root->right);

    return leftval + rightval;
}