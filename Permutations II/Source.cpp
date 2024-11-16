#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        vector<vector<int>> result;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        BackTrack(nums, curr, result);
        return result;
    }

    void BackTrack(vector<int>& nums, vector<int>& curr, vector<vector<int>>& result)
    {
        if (nums.size() == curr.size())
        {
            result.push_back(curr);
            return;
        }

        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == -11) { continue; }

            if (i > 0 && nums[i] == nums[i - 1] && nums[i - 1] != -11)
            {
                continue;
            }


            int tmp = nums[i];
            curr.push_back(nums[i]);
            nums[i] = -11;
            BackTrack(nums, curr, result);
            curr.pop_back();
            nums[i] = tmp;

        }


    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1,1,2 };
    s.permuteUnique(nums);
    return 0;
}