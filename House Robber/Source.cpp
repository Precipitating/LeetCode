#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int rob(vector<int>& nums) 
    {
        if (nums.size() == 0) { return 0; }
        vector<int> memoize(nums.size() + 1);
        memoize[0] = 0;
        memoize[1] = nums[0];

        for (int i = 1; i < nums.size(); ++i)
        {
            memoize[i + 1] = max(memoize[i - 1] + nums[i], memoize[i]);
        }

        return memoize[nums.size()];
    }


    int RobOrNot(int i, const vector<int>& nums)
    {
        if (i < 0) { return 0; }
        return max(RobOrNot(i - 2, nums) + nums[i], RobOrNot(i - 1, nums));
    }
};


int main()
{
    Solution s;
    vector<int> nums = { 1,2,3,1 };
    cout << s.rob(nums);
    return 0;
}