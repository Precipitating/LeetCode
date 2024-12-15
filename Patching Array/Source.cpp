#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minPatches(vector<int>& nums, int n)
    {
        long miss = 1;
        long patch = 0;
        int i = 0;

        while (miss <= n)
        {
            if (i < nums.size() && nums[i] <= miss)
            {
                miss += nums[i++];
            }
            else
            {
                miss += miss;
                ++patch;
            }
        }

        return patch;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1,5,10 };
    s.minPatches(nums, 20);

    return 0;
}