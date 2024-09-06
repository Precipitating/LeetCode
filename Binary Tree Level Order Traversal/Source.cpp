#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> result;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        while (!nodeQueue.empty())
        {
            vector<int> currentLine;
            int currSize = nodeQueue.size();

            for (size_t i = 0; i < currSize; ++i)
            {
                TreeNode* curr = nodeQueue.front(); nodeQueue.pop();

                if (curr != nullptr)
                {
                    currentLine.push_back(curr->val);
                    nodeQueue.push(curr->left);
                    nodeQueue.push(curr->right);
                }


            }

            if (currentLine.size() > 0)
            {
                result.push_back(move(currentLine));
            }
            


        }


        return result;
    }


};

int main()
{
    Solution s;
    //TreeNode* node = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    TreeNode* node = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3, nullptr, new TreeNode(7)));
    s.levelOrder(node);
    return 0;
}