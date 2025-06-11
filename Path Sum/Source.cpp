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
	~TreeNode() { delete left; delete right; }
};

class Solution
{
public:
	bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if (root)
        {
            if (!root->left && !root->right)
            {
                if (targetSum - root->val != 0)
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }

            bool isLeft = hasPathSum(root->left, targetSum - root->val);
            if (isLeft) return true;
            bool isRight = hasPathSum(root->right, targetSum - root->val);
            if (isRight) return true;
        }


        return false;

	}
};

int main()
{
	Solution s;
    TreeNode* root = new TreeNode(5,
        new TreeNode(4,
            new TreeNode(11,
                new TreeNode(7),
                new TreeNode(2)
            ),
            nullptr
        ),
        new TreeNode(8,
            new TreeNode(13),
            new TreeNode(4,
                nullptr,
                new TreeNode(1)
            )
        )
    );

    TreeNode* empty = nullptr;
    s.hasPathSum(root, 22);


	return 0;
}