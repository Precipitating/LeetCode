#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution 
{
public:
    int splitArray(vector<int>& nums, int k) 
    {
        int left = *max_element(nums.begin(), nums.end()), right = accumulate(nums.begin(), nums.end(), 0);
        result = right;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (CanSplit(mid, nums, k))
            {
                result = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }

        }

        return result;
    }

    bool CanSplit(int largest, const vector<int>& nums, int k)
    {
        int subarray = 0;
        int currSum = 0;

        for (int n : nums)
        {
            currSum += n;
            if (currSum > largest)
            {
                subarray += 1;
                currSum = n;
            }
        }

        return subarray + 1 <= k;
    }

private:
    int result = 0;
};

int main()
{
    Solution s;
    vector<int> nums = { 7,2,5,10,8 };
    s.splitArray(nums, 2);
    return 0;
}