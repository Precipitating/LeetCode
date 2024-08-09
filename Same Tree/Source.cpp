#include <iostream>
using namespace std;


struct TreeNode {
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
    // O(n) recursion solution.
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        // get out of potential recursion hell if its already determined its not same
        if (!isSame) { return isSame; }

        // handle nullptrs seperately, as we can't access nullptr member variables
        if ((p == nullptr) && (q == nullptr))
        {
            isSame = true;
            return isSame;
        }
        // if one is true, and other false, its auto false
        if ((p == nullptr) ^ (q == nullptr))
        {
            isSame = false;
            return isSame;
        }

        // check for equality
        if (p->val == q->val)
        {
            // go both left/right routes and check them side by side
            isSameTree(p->left, q->left);
            isSameTree(p->right, q->right);

        }
        else
        {
            isSame = false;

        }

        return isSame;
    }

private:
    bool isSame = true;
};

int main()
{
    Solution s;
    TreeNode* node = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* node2 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    cout << s.isSameTree(node, node2);
    return 0;
}