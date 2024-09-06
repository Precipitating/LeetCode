#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        // true = left->right | false = right->left
        bool zigZagSwitch = false;
        vector<vector<int>> result;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        while (!nodeQueue.empty())
        {
            deque<int> currentLine;
            int currSize = nodeQueue.size();

            for (size_t i = 0; i < currSize; ++i)
            {
                TreeNode* curr = nodeQueue.front(); nodeQueue.pop();
                

                if (curr != nullptr)
                {
                    if (zigZagSwitch)
                    {
                        currentLine.push_front(curr->val);

                    }
                    else
                    {
                        currentLine.push_back(curr->val);

                    }

                    if (curr->left) { nodeQueue.push(curr->left); }
                    if (curr->right) { nodeQueue.push(curr->right); }


                }



            }

            if (currentLine.size() > 0)
            {
                result.push_back(vector<int>(currentLine.begin(), currentLine.end()));
                
            }

            zigZagSwitch = !zigZagSwitch;


        }


        return result;
    }


};

int main()
{
    Solution s;
    //TreeNode* node = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    TreeNode* node = new TreeNode(1, new TreeNode(2, new TreeNode(4), nullptr), new TreeNode(3, nullptr, new TreeNode(5)));
    //TreeNode* node = new TreeNode(2,nullptr,new TreeNode(3,nullptr, new TreeNode(4,nullptr, new TreeNode(5,nullptr, new TreeNode(6)))));
    s.zigzagLevelOrder(node);
    return 0;
}