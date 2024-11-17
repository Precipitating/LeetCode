#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        vector<vector<int>> result;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        BackTrack(0, nums, curr, result);
        return result;

    }

    void BackTrack(int idx, const vector<int>& nums, vector<int>& curr, vector<vector<int>>& result)
    {
        result.push_back(curr);

        for (int i = idx; i < nums.size(); ++i)
        {
            if (i > idx && nums[i] == nums[i - 1])
            {
                continue;
            }
            curr.push_back(nums[i]);
            BackTrack(i + 1, nums, curr, result);
            curr.pop_back();
        }

    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1,2,2 };
    s.subsetsWithDup(nums);
    return 0;
}