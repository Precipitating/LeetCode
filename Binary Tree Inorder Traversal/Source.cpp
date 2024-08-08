#include <iostream>
#include <vector>
#include <stack>
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

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        stack<TreeNode*> stack;

        vector<int> result;

        while (root != nullptr || !stack.empty())
        {
            // get furthest left node
            while (root != nullptr)
            {
                stack.push(root);
                root = root->left;
            }

            root = stack.top();
            // add to result and go back to follow the inorder traversal
            result.push_back(root->val);
            stack.pop();


            root = root->right;


        }







        return result;

    }

};
int main()
{
    Solution s;
    TreeNode* node = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3,nullptr, new TreeNode(6)));

    s.inorderTraversal(node);

    delete node;


    return 0;
}