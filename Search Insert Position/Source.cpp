#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution
{
public:
    // SOLUTION 1: BINARY SEARCH - fast 3ms
    int searchInsert(vector<int>& nums, int target)
    {
        int answer = 0;
        int midPoint;
        int start = 0, end = nums.size() - 1;


        while (start <= end )
        {
            midPoint = start + (end - start) / 2;


            if (nums[midPoint] == target)
            {
                return midPoint;
            }

            // go RIGHT if midpoint less than target
            if (nums[midPoint] < target)
            {
                start = midPoint + 1;
            }
            else
            {
                end = midPoint - 1;
            }

        }


        return start;

    }

    // SOLUTION 2: SLOWER BUT READABLE AND CLEANER.
    //int searchInsert(vector<int>& nums, int target)
    //{
    //    // lower bound attempts to find the iterator to the number, and if it doesn't exist
    //    // returns the iterator to the nearest number to target thats below the target value.
    //    auto it = lower_bound(nums.begin(), nums.end(), target);
    //    int idx = distance(nums.begin(), it);

    //    return idx;

    //}

};


int main()
{
    Solution s;
    vector<int> nums = { 1,3,5,6 };
    int val = 7;

    int pos = s.searchInsert(nums, val);

    return 0;
}