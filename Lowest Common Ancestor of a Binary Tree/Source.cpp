#include <iostream>
using namespace std;


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    ~TreeNode() {delete left; delete right;}
};

class Solution
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        TreeNode* result = nullptr;
        result = Solve(root, p, q);

        return result;


    }

    TreeNode* Solve(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (!root) { return nullptr; }

        if (root == p || root == q) { return root; }

        TreeNode* left = Solve(root->left, p, q);
        TreeNode* right = Solve(root->right, p, q);

        if (left && right) { return root; }

        return left ? left : right;

    }
};


int main()
{
    Solution s;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    cout << s.lowestCommonAncestor(root, root->right, root->right->left)->val;

    return 0;
}