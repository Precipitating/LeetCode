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

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        
        int left = 0;
        int right = nums.size() - 1;

        if (nums.empty()) { return nullptr; }

        TreeNode* root = ConvertArray(nums, left, right);
        return root;

    }

    TreeNode* ConvertArray(const vector<int>& nums, int left, int right)
    {
        if (left > right) { return nullptr; }

        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = ConvertArray(nums, left, mid - 1);
        node->right = ConvertArray(nums, mid+1, right);
        return node;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    s.sortedArrayToBST(nums);


	return 0;
}