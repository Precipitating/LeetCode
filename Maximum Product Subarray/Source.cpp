#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxProduct(vector<int>& nums)
    {
        if (nums.size() == 1) { return nums[0]; }
        
        int minNum = nums[0];
        int maxNum = nums[0];
        int result = nums[0];

        for (size_t i = 1; i < nums.size(); ++i)
        {
            int curr = nums[i];
            // two negs can create a positive so track it
            int currMax = max(curr, max(maxNum * curr, minNum * curr));
            minNum = min(curr, min(maxNum * curr, minNum * curr));

            maxNum = currMax;

            result = max(result, maxNum);
        }

        return result;

    }
};

int main()
{

    Solution s;
    vector<int> nums = { 2,0,-2,4 };
    cout << s.maxProduct(nums);


    return 0;
}