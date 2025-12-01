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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 1) return new TreeNode(nums[0]);
        int maxval = 0;
        int index = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] > maxval)
            {
                maxval = nums[i];
                index = i;
            }
        }
             
        TreeNode * root = new TreeNode(maxval);
        if ( index > 0)
        {
            vector<int> leftnums(nums.begin(), nums.begin() + index);
            root->left = constructMaximumBinaryTree(leftnums);
        }
        if ( index < nums.size() - 1)
        {
            vector<int> rightnums(nums.begin() + index + 1, nums.end());
            root->right = constructMaximumBinaryTree(rightnums);
        }
        
        return root;
    }
};