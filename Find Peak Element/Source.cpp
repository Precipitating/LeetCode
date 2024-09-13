#include <iostream>
#include <vector>
using namespace std;


class Solution
{
public:
    int findPeakElement(vector<int>& nums)
    {
        if (nums.size() == 1) { return 0; }
        int result = -1;
        int low = 0, high = nums.size() - 1;


        while (low <= high && result == -1)
        {
            int half = low + ((high - low) / 2);

            // out of bounds = -INF
            if (half + 1 == nums.size() || half - 1 < 0)
            {
                if (half + 1 == nums.size())
                {
                    if (nums[half - 1] < nums[half])
                    {
                        result = half;
                    }
                    else
                    {
                        --high;
                    }
                }
                else if (half - 1 < 0)
                {
                    if (nums[half + 1] < nums[half])
                    {
                        result = half;
                    }
                    else
                    {
                        ++low;
                    }
                }
            }
            else
            {
                // if middle is the peak, return it.
                if (nums[half - 1] < nums[half] && nums[half + 1] < nums[half])
                {
                    result = half;
                }
                else
                {
                    if (nums[half + 1] > nums[half])
                    {
                        low = half + 1;
                    }
                    else
                    {
                        high = half - 1;
                    }
                }



            }

        }
        return result;
    }


};

int main()
{
    Solution s;
    vector<int> nums = { 1,2,3,1,100,200,300,400,500,600,700 };
    s.findPeakElement(nums);
    return 0;
}