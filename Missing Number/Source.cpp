#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // o log n version
    //int missingNumber(vector<int>& nums)
    //{
    //    int result = -1;
    //    int range = nums.size();
    //    int start = 0;
    //    sort(nums.begin(), nums.end());
    //    while (start < range)
    //    {
    //        if (nums[start] != start)
    //        {
    //            result = start;
    //            break;
    //        }
    //        ++start;
    //    }
    //    if (result == -1)
    //    {
    //        result = range;
    //    }
    //    return result;
    //}

    // xor version o(n)
    // xor two same numbers = 0
    // missing number should only be 1 number, so it won't = 0
    // o(N) solution
    int missingNumber(vector<int>& nums)
    {
        int result = 0;
        int idx = 0;

        for (size_t i = 0; i <= nums.size(); ++i)
        {
            result ^= i;
        }
        for (size_t i = 0; i < nums.size(); ++i)
        {
            result ^= nums[i];
        }

        return result;
    }
};


int main()
{
    Solution s;
    vector<int> nums = {0,4,1,2};
    cout << s.missingNumber(nums);

}