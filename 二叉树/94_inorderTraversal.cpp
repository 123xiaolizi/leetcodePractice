#include <vector>
#include <stack>
// 给你二叉树的根节点 root ，返回它节点值的 中序 遍历。
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



class Solution {
public:

/////////////////////////递归法/////////////////////////////////
    void  traversal(TreeNode* root, vector<int> &vec)
    {
        if(root == nullptr) return;
        traversal(root->left, vec); 
        vec.emplace_back(root->val);
        traversal(root->right, vec);      
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
//////////////////////////非递归////////////////////////////////////////
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> res;
        if (root == nullptr) return res;
        TreeNode* cur = root;
        stack<TreeNode*> st;
        while(cur != nullptr || !st.empty())
        {
            if(cur != nullptr)
            {
                st.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = st.top();
                st.pop();
                res.emplace_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }

};