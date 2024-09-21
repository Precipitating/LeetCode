#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {

        vector<int> leftProducts(nums.size(), 1);
        leftProducts[1] = nums[0];

        for (int i = 2; i < nums.size(); ++i)
        {
            leftProducts[i] = leftProducts[i - 1] * nums[i - 1];
        }

        int num = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i > -1 ; --i)
        {
            leftProducts[i] *= num;
            num *= nums[i];

        }

        return leftProducts;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 2,3,4,5};
    s.productExceptSelf(nums);

    return 0;
}