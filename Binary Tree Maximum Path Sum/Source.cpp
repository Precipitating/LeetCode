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
    ~TreeNode() { delete left; delete right; }
};

class Solution
{
public:
    int maxPathSum(TreeNode* root) 
    {
        int maxVal = INT_MIN;

        GetMaxRoot(root, maxVal);

        return maxVal;

    }

    int GetMaxRoot(TreeNode* root, int& maxVal)
    {
        if (root == nullptr) { return 0; }

        int left = max(0, GetMaxRoot(root->left, maxVal));
        int right = max(0, GetMaxRoot(root->right, maxVal));

        maxVal = max(maxVal, root->val + left + right);

        return root->val + max(left, right);

    }


};

int main()
{
    Solution s;
    TreeNode* node = new TreeNode(-10, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    s.maxPathSum(node);
    return 0;
}