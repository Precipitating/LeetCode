#include <iostream>
#include <vector>
using namespace std;


class Solution
{
public:
    int search(vector<int>& nums, int target) 
    {
        if (nums.empty()) { return -1; }

        int first = 0, last = nums.size() - 1;
        int result = -1;
        int half = first + ((last - first) / 2);

        // determine which side it's on
        // check left & right
        while (first <= last)
        {
            half = first + ((last - first) / 2);
            if (target == nums[half]) { result = half; break; }

            // check left
            if (nums[first] <= nums[half])
            {
                if (target > nums[half] || target < nums[first])
                {
                    first = half + 1;
                }
                else
                {
                    last = half - 1;
                }

            }
            // check right
            else if (target < nums[half] || target > nums[last])
            {
                last = half - 1;
            }
            else
            {
                first = half + 1;
            }


        }



        return result;
    }
};


int main()
{
    Solution s;
    vector<int> nums = { 6, 7, 0, 1, 2, 4, 5 };
    cout << s.search(nums, 0);
}