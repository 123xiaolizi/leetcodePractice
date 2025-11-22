#include <vector>
#include <stack>
// 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
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

// 非递归
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> res;
    if (root == nullptr)
        return res;
    stack<TreeNode *> st;
    TreeNode *cur = nullptr;
    st.push(root);
    while (!st.empty())
    {
        cur = st.top();
        st.pop();
        res.emplace_back(cur->val);
        if (cur->right != nullptr)
            st.push(cur->right);
        if (cur->left != nullptr)
            st.push(cur->left);
    }
    return res;
}

//递归法
void  traversal(TreeNode* root, vector<int> &vec)
{
    if(root == nullptr) return;
    vec.emplace_back(root->val);
    traversal(root->left, vec);
    traversal(root->right, vec);
}
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> vec;
    traversal(root, vec);
    return vec;
}
