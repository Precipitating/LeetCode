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
    vector<TreeNode*> generateTrees(int n) 
    { 
        return Solve(1, n);
    }

    vector<TreeNode*> Solve(int start, int end)
    {
        vector<TreeNode*> curr;
        if (start > end)
        {
            curr.push_back(nullptr);
            return curr;
        
        }

        for (int i = start; i <= end; ++i)
        {
            // get all permutations
            vector<TreeNode*> left = Solve(start, i - 1);
            vector<TreeNode*> right = Solve(i + 1, end);

            for (int j = 0; j < left.size(); ++j) 
            {
                for (int k = 0; k < right.size(); ++k) 
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    curr.push_back(root);
                }
            }
        }

        return curr;
    }
};

int main()
{
    Solution s;
    s.generateTrees(3);
    return 0;
}