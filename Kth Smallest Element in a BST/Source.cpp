#include <iostream>
#include <vector>
using namespace std;


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    ~TreeNode() { delete left; delete right; }
};

class Solution
{
public:
    int kthSmallest(TreeNode* root, int k)
    {
        if (!root->left && !root->right) { return root->val; }
        int result = -1;
        // sort this ascending
        inOrderTraversal(root, k, result);

        return result;

    }

    void inOrderTraversal(TreeNode* root, int& k, int& answer)
    {
        if (!root || answer != -1) { return; }
                                        
        inOrderTraversal(root->left, k, answer);
        --k;
        if (k == 0) { answer = root->val; }
        inOrderTraversal(root->right,k, answer);


    }
};


int main()
{
    Solution s;
    TreeNode* node = new TreeNode(5, new TreeNode(3, new TreeNode(2, new TreeNode(1), nullptr), new TreeNode(4)), new TreeNode(6));
    //TreeNode* node = new TreeNode(3, new TreeNode(1,nullptr, new TreeNode(2)), new TreeNode(4));
   //TreeNode* node = new TreeNode(1, nullptr, new TreeNode(2));
    cout << s.kthSmallest(node, 3);
    return 0;
}