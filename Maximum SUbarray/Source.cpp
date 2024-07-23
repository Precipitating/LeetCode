#include <iostream>
#include <vector>
#include <numeric>
using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }

        int maxNum = INT_MIN;
        int maxEndingHere = 0;

        for (size_t i = 0; i < nums.size(); ++i)
        {
            maxEndingHere = max(nums[i], maxEndingHere + nums[i]);
            maxNum = max(maxNum, maxEndingHere);
   
        }


        return maxNum;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { -2,-1};

    int maxNum = s.maxSubArray(nums);


    cout << maxNum;


    return 0;

}