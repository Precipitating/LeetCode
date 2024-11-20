#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int result = 0;
        Solve(0, 0, nums, target, result);

        return result;
    }

    void Solve(int idx, int currSum, const vector<int>& nums, int target, int &result)
    {

        if (idx == nums.size())
        {
            if (currSum == target)
            {
                ++result;
            }
            return;
        }

        Solve(idx + 1, currSum + nums[idx], nums, target, result);
        Solve(idx + 1, currSum - nums[idx], nums, target, result);

    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1,1,1,1,1 };
    s.findTargetSumWays(nums, 3);

    return 0;
}