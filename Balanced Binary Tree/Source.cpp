#include <iostream>
using namespace std;



struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    ~TreeNode()
    {
        delete left;
        delete right;
        left = nullptr; right = nullptr;
    }
};

class Solution
{
public:
    bool isBalanced(TreeNode* root)
    {
        if (root == nullptr) { return true; }
        bool isBalanced = true;

        // check root height
        GetDepth(root, isBalanced);



        return isBalanced;

    }

    // o(n), get end of a subtree and check backwards.
    int GetDepth(TreeNode* root, bool& isBalanced)
    {
        if (root == nullptr) { return -1; }
        int left = GetDepth(root->left, isBalanced);
        int right = GetDepth(root->right, isBalanced);

        if (abs(left - right) > 1)
        {
            isBalanced = false;
        }

        return max(left, right) + 1;


    }
};



int main()
{
    Solution s;
    TreeNode* node = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    TreeNode* node2 = new TreeNode(1, new TreeNode(2, new TreeNode(3, new TreeNode(4), new TreeNode(4)), new TreeNode(3)), new TreeNode(2));
    TreeNode* node3 = new TreeNode(1, new TreeNode(2, new TreeNode(3, new TreeNode(4),nullptr),nullptr), new TreeNode(2,nullptr, new TreeNode(3)));
    cout << s.isBalanced(node3);

    delete node; delete node2; delete node3;
    return 0;
}