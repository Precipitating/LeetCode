#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int countMaxOrSubsets(vector<int>& nums)
    {
        int result = 0;
        vector<vector<int>> subSets;
        vector<int> curr;
        int maxOr = 0;

        // get max OR value 
        for (size_t i = 0; i < nums.size(); i++)
        {
            maxOr |= nums[i];
        }

        GetSubSets(0, 0, maxOr, nums, result);



        return result;



    }

    void GetSubSets(int idx, int currVal, int target, const vector<int>& nums, int& result)
    {
        if (idx >= nums.size())
        {
            if (currVal == target)
            {
                ++result;

            }
            return;

        }


        GetSubSets(idx + 1, currVal, target, nums, result);
        GetSubSets(idx + 1, currVal | nums[idx], target, nums, result);



    }
};

int main()
{
    Solution s;
    vector<int> nums = { 3,1 };
    s.countMaxOrSubsets(nums);
    return 0;
}