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
    //一刷，效率很差
    TreeNode* mergeTrees_1(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) return nullptr;
        TreeNode* root_result = new TreeNode(0);
        if(root1 != nullptr && root2 != nullptr)
        {
            root_result->val = root1->val + root2->val;
            root_result->left = mergeTrees(root1->left, root2->left);
            root_result->right = mergeTrees(root1->right, root2->right);
            return root_result;
        }
        else if (root1 != nullptr && root2 == nullptr)
        {
            root_result->val = root1->val;
            root_result->left = mergeTrees(root1->left, root2);
            root_result->right = mergeTrees(root1->right, root2);
            return root_result;
        }
        else
        {
            root_result->val = root2->val;
            root_result->left = mergeTrees(root1, root2->left);
            root_result->right = mergeTrees(root1, root2->right);
            return root_result;
        }
        
    }
    //直接复用root1，也可以重新构建一个新的树
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr) return root2;
        if (root2 == nullptr) return root1;

        // 重新构建一个新的树
        // TreeNode* res_root = new TreeNode(root1->val + root2->val);
        // res_root->left = mergeTrees(root1->left, root2->left);
        // res_root->right = mergeTrees(root1->right, root2->right);
        // return res_root;

        //直接复用root1
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
        
    }
};