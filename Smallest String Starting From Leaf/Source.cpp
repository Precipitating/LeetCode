#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    ~TreeNode() { delete left; delete right; left = nullptr; right = nullptr; }
};

class Solution
{
public:
    string smallestFromLeaf(TreeNode* root) 
    {
        // basically max string val
        string result = "~";
        string curr;
        Solve(curr,result, root);

        return result;
    }

    void Solve(string curr, string& result, TreeNode* root)
    {
        if (!root) { return; }
        curr += root->val + 'a';
        if (!root->left && !root->right)
        {
            reverse(curr.begin(), curr.end());
            result = min(curr, result);
            return;
        }
        Solve(curr, result, root->left);
        Solve(curr, result, root->right);

    }


};

int main()
{
    Solution s;
    TreeNode* root = new TreeNode(0, new TreeNode(1, new TreeNode(3), new TreeNode(4)), new TreeNode(2, new TreeNode(3), new TreeNode(4)));
    s.smallestFromLeaf(root);


    delete root;
    root = nullptr;
    return 0;
}