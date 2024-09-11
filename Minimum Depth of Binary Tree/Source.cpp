#include <iostream>
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
    
    ~TreeNode() { delete left; delete right; left = nullptr; right = nullptr; }
};

class Solution
{
public:
    int minDepth(TreeNode* root) 
    {
        if (!root) { return 0; }
        int answer = 0;
        queue<TreeNode*> bfs;
        bfs.push(root);


        while (!bfs.empty())
        {
            int levelSize = bfs.size();      
            ++answer;

            for (size_t i = 0; i < levelSize; ++i)
            {
                TreeNode* curr = bfs.front();
                bfs.pop();
                
                // found shortest exit early
                if (!curr->left && !curr->right)
                {
                    return answer;
                }

                if (curr->left) { bfs.push(curr->left); }
                if (curr->right) { bfs.push(curr->right); }
            }





        }


        return 0;
    }
};

int main()
{
    Solution s;
    //TreeNode* node = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    TreeNode* node = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));
    cout << s.minDepth(node);
    return 0;
}