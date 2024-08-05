#include <iostream>
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
     TreeNode* invertTree(TreeNode* root)
     {
         if (!root)
         {
             return nullptr;
         }

        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);

        return root;


     }
    

 };


 int main()
 {
     Solution s;
     
     TreeNode* thirdR = new TreeNode(9);
     TreeNode* thirdL = new TreeNode(6);
     TreeNode* secR = new TreeNode(3);
     TreeNode* secL = new TreeNode(1);
     TreeNode* firstR = new TreeNode(7,thirdL,thirdR);
     TreeNode* firstL = new TreeNode(2,secL,secR);
     TreeNode* root = new TreeNode(4,firstL, firstR);

     s.invertTree(root);
 }

 