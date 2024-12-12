#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    int jump(vector<int>& nums)
    {
        int furthest = 0, currentEnd = 0;
        
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            furthest = max(furthest, nums[i] + i);

            if (i == currentEnd)
            {
                ++result;
                currentEnd = furthest;
            }


        }

        return result;
    }

private:
    int result = 0;
};

int main()
{
    Solution s;
    vector<int> nums = { 1,2,1,1,1 };
    s.jump(nums);
    return 0;
}