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
    void TreePaths(TreeNode* node, vector<int>& path, vector<string> &result)
    {
        path.push_back(node->val);
        if(node->left == nullptr && node->right == nullptr)
        {
            string temp;
            for(int i = 0; i < path.size() - 1; ++i)
            {
                temp += to_string(path[i]);
                temp += "->";
            }
            temp += to_string(path[path.size()-1]);
            result.push_back(temp);
            return;
        }
        
        if(node->left)
        {
            TreePaths(node->left, path, result);
            //注意这里是回溯的关键
            path.pop_back();
        }
        if(node->right)
        {
            TreePaths(node->right, path, result);
            //注意这里是回溯的关键
            path.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> result;
        TreePaths(root, path, result);
        return result;
    }
};