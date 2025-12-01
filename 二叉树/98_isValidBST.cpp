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
    void help(TreeNode* node, vector<int> &nums)
    {
        if(node == nullptr) return;
        help(node->left, nums);
        nums.emplace_back(node->val);
        help(node->right, nums);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> nums;
        help(root, nums);
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] <= nums[i - 1])
            {
                return false;
            }
        }
        return true;
    }
};