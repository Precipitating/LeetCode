#include <iostream>
using namespace std;


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    ~TreeNode()
    {
        delete left;
        delete right;
    }
};

class Solution
{
public:
    int maxDepth(TreeNode* root) 
    {
        if (!root) { return 0; }

        int currentDepth = 1;
        int result = 1;
        getDepth(root,currentDepth, result);
        
        return result;


    }

    void getDepth(TreeNode* root, int currentDepth, int& result)
    {
        result = max(currentDepth, result);
        if (root->left != nullptr)
        {
            getDepth(root->left, currentDepth + 1, result);
        }
        if (root->right != nullptr)
        {
            getDepth(root->right, currentDepth + 1, result);
        }



    }

};

int main()
{
    Solution s;
    TreeNode* node = new TreeNode(1,nullptr, new TreeNode(2));
    cout << s.maxDepth(node);

    delete node;

    return 0;

}