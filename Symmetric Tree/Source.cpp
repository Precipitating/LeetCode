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
        delete left;  // Recursively delete left subtree
        delete right; // Recursively delete right subtree
    }
};
 
class Solution
{
public:
    bool isSymmetric(TreeNode* root)
    {
        bool isSymmetric = true;
        TreeNode* rootCopyL = root->left;
        TreeNode* rootCopyR = root->right;


        // swap a side
        swapNode(root->left);
        compareNode(rootCopyL, rootCopyR, isSymmetric);




        return isSymmetric;
    }

    void compareNode(TreeNode* left, TreeNode* right, bool& result)
    {
        bool onlyOneNull = (left == nullptr) ^ (right == nullptr);
        if (onlyOneNull)
        {
            result = false;
            return;
        }

        if (left != nullptr && right != nullptr)
        {

            if (left->val != right->val)
            {
                result = false;
                return;
            }
            compareNode(left->left, right->left,result);
            compareNode(left->right, right->right,result);


        }

        

    }

    void swapNode(TreeNode* node)
    {
        if (node != nullptr)
        {
            swap(node->left, node->right);
            swapNode(node->left);
            swapNode(node->right);

        }
    }
};


int main()
{

    TreeNode* main = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(2, new TreeNode(4), new TreeNode(3)));
    TreeNode* falseOption = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(3)), new TreeNode(2, nullptr, new TreeNode(3)));

    Solution s;
    cout << s.isSymmetric(main);
    
    delete main;

}