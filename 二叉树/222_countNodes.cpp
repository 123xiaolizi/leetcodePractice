
//普通递归遍历简单易懂,也可以不需要辅助函数，但是我觉得这样写比较好理解
void help(TreeNode* node, int &count)
{
    if(node == nullptr) return;
    ++count;
    help(node->left, count);
    help(node->right, count);
    
}
int countNodes(TreeNode* root) {
    int count = 0;
    help(root, count);
    return count;
}



//利用完全二叉树的定义，达到剪枝的效果，在数据量大的树可以提高性能
int countNodes(TreeNode* root)
{
    if(root == nullptr) return 0;
    TreeNode* left = root->left;
    TreeNode* right = root->right;
    int left_depth = 0;
    int right_depth = 0;
    while(left)
    {
        ++left_depth;
        left = left->left;
    }
    while(right)
    {
        ++right_depth;
        right = right->right;
    }
    if(left_depth == right_depth) return ((2 << left_depth) - 1);

    int count_left = countNodes(root->left); //左
    int count_right = countNodes(root->right);//右
    return (count_left + count_right) + 1;//别忘了“根节点” 中
}