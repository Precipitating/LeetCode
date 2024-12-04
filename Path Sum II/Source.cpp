#include <iostream>
#include <vector>
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<int> curr;
        Solve(root, curr,targetSum);

        return result;
    }

    void Solve(TreeNode* root, vector<int>& curr, int target)
    {
        if (!root) { return; }
        curr.push_back(root->val);
        if (!root->left && !root->right && target == root->val)
        { 
            result.push_back(curr);

        }
        else
        {
            Solve(root->left, curr, target - root->val);
            Solve(root->right, curr, target - root->val);
        }
        curr.pop_back();






    }
private:
    vector<vector<int>> result;
};

int main()
{
    Solution s;
    TreeNode* root = new TreeNode(5, new TreeNode(4, new TreeNode(11, new TreeNode(7),
                     new TreeNode(2)), nullptr), new TreeNode(8, new TreeNode(13), new
                         TreeNode(4, new TreeNode(5), new TreeNode(1))));
    s.pathSum(root, 22);
    return 0;
}