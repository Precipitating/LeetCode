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
    bool isValidBST(TreeNode* root)
    {
        return isValid(root, LONG_MIN, LONG_MAX);
    }

    // in order traversal
    bool isValid(TreeNode* root, long minRange, long maxRange)
    {
        if (!root) { return true; }

        // out of bounds
        if (root->val <= minRange || root->val >= maxRange)
        {
            return false;
        }

        // left = should be BELOW root value | right = should be ABOVE the root value
        return (isValid(root->left, minRange, root->val) && isValid(root->right, root->val, maxRange));


    }

};

int main()
{
    Solution s;
    TreeNode* node = new TreeNode(2, new TreeNode(1), new TreeNode(3));
   // TreeNode* node = new TreeNode(5, new TreeNode(1), new TreeNode(4, new TreeNode(3), new TreeNode(6)));
    //TreeNode* node = new TreeNode(5, new TreeNode(4), new TreeNode(6, new TreeNode(3), new TreeNode(7)));
    //TreeNode* node = new TreeNode(1, new TreeNode(1), nullptr);
    cout << s.isValidBST(node);

    delete node;


}