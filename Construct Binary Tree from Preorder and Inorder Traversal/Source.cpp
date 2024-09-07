#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    ~TreeNode() { delete left; delete right; }
};

class Solution
{
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        if (preorder.empty() || inorder.empty()) { return nullptr; }
        unordered_map<int, int> map;
        // root is always first number in pre-order
        
        // cache numbers

        for (size_t i = 0; i < inorder.size(); ++i)
        {
            map[inorder[i]] = i;
        }


        TreeNode* answer = Solve(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, map);

        return answer;
    }




    TreeNode* Solve(const vector<int>& preOrder, int preStart, int preEnd,
                    const vector<int>& inOrder, int inStart, int inEnd, unordered_map<int,int>& map)
    {
        if (preStart > preEnd || inStart > inEnd) { return nullptr; }
        TreeNode* node = new TreeNode(preOrder[preStart]);

        int rootInOrder = map[node->val];
        int leftCount = rootInOrder - inStart;

        node->left = Solve(preOrder, preStart + 1, preStart + leftCount, inOrder, inStart, rootInOrder - 1, map);
        node->right = Solve(preOrder, preStart + leftCount + 1, preEnd, inOrder, rootInOrder+1, inEnd, map);

        return node;
    }

};

int main()
{
    Solution s;
    vector<int> preOrder = { 10,20,40,50,30,60 };
    vector<int> inOrder = { 40,20,50,10,60,30 };

    s.buildTree(preOrder,inOrder);
    return 0;
}