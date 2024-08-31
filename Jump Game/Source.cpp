#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        if (nums.size() == 1) { return true; }
        int lastIdx = nums.size() - 1;
        bool result = false;
        int furthest = 0;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (i > furthest) { break; }
            furthest = max(furthest, i + nums[i]);
            if (furthest >= lastIdx)
            {
                result = true;
                break;
            }


        }

        return result;

    }


};


int main()
{
    Solution s;
    vector<int> nums = { 0,2,3};
    cout << s.canJump(nums);

}