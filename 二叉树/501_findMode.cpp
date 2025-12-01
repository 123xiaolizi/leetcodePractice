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
    int count = 1;
    int Maxcount = 1;
    vector<int> result;
    TreeNode* pre = nullptr;
    void getresult(TreeNode* cur)
    {
        if (cur == nullptr) return;
        getresult(cur->left);
        if(pre)
        {
            if(cur->val == pre->val)
            {
                ++count;
            }
            else
            {
                count = 1; //重置
            }
        }
        pre = cur;
        if(count == Maxcount) result.emplace_back(cur->val);//这里只是临时放进去，不一定是最终值，看下面逻辑
        if(count > Maxcount)
        {
            Maxcount = count;
            result.clear();
            result.emplace_back(cur->val);
        }
        getresult(cur->right);
    }
    vector<int> findMode(TreeNode* root) {
        getresult(root);
        return result;
    }
};