#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

 struct TreeNode 
 {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     ~TreeNode()
     {
         delete left; left = nullptr;
         delete right; right = nullptr;

     }
 };
 
class Solution 
{
public:
    TreeNode* balanceBST(TreeNode* root)
    {
        if (!root) { return nullptr; }
        toSortedList.push_back(root->val);
        InorderTraverse(root->left, root);
        InorderTraverse(root->right, root);

        sort(toSortedList.begin(), toSortedList.end());
        return BuildTree(0, toSortedList.size() - 1);

    }


    void InorderTraverse(TreeNode* root, TreeNode* prev)
    {
        if (root)
        {
            InorderTraverse(root->left, root);
            toSortedList.push_back(root->val);
            InorderTraverse(root->right, root);     
        }
    }

    TreeNode* BuildTree(int start, int end)
    {
        if (start > end) { return nullptr; }

        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(toSortedList[mid]);

        root->left = BuildTree(start, mid - 1);
        root->right = BuildTree(mid + 1, end);

        return root;

    }
private:
    vector<int> toSortedList;
    TreeNode* result = new TreeNode();
};

int main()
{
    Solution s;
    TreeNode* node = new TreeNode(1, nullptr, new TreeNode(2, nullptr, new TreeNode(3, nullptr, new TreeNode(4))));
    s.balanceBST(node);
    return 0;
}