#include <iostream>
#include <vector>
using namespace std;


class Solution
{
public:
    int findPeakElement(vector<int>& nums)
    {
        int low = 0, high = nums.size() - 1;

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            // if middle less than next element, move right
            if (nums[mid] < nums[mid + 1])
            {
                low = mid + 1;
            }
            else
            {
                // else peak is left or itself is the peak.
                high = mid;
            }

        }

        return low;

    }


};

int main()
{
    Solution s;
    vector<int> nums = { 1,2,3,1,100,200,300,400,500,600,700 };
    cout << s.findPeakElement(nums);
    return 0;
}