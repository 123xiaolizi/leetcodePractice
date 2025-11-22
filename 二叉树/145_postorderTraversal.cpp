#include <vector>
#include <stack>
#include <algorithm>
// 给你二叉树的根节点 root ，返回它节点值的 后序 遍历。
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

//非递归的方法
/*
先序遍历是中左右，后序遍历是左右中，
那么我们只需要调整一下先序遍历的代码顺序，就变成中右左的遍历顺序，
然后在反转result数组，输出的结果顺序就是左右中了
*/
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> res;
        if(root == nullptr) return res;
        stack<TreeNode*> st;
        TreeNode* cur = nullptr;
        st.push(root);
        while(!st.empty())
        {
            cur = st.top();
            st.pop();
            res.emplace_back(cur->val);
            if(cur->left != nullptr) st.push(cur->left);
            if(cur->right != nullptr) st.push(cur->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }

//递归的方法
// void  traversal(TreeNode* root, vector<int> &vec)
    // {
    //     if(root == nullptr) return;
    //     traversal(root->left, vec); 
    //     traversal(root->right, vec);
    //     vec.emplace_back(root->val);
    // }
    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> result;
    //     traversal(root, result);
    //     return result;
    // }

};