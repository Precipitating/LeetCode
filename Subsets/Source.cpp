#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> result;
        vector<int> currentSet;

        RecursiveCheck(0, nums, result, currentSet);
        return result;
    }

    void RecursiveCheck(int curr, const vector<int>& nums, vector<vector<int>> &result, vector<int>& currentSet)
    {
        result.push_back(currentSet);
        for (size_t i = curr; i < nums.size(); ++i)
        {
            currentSet.push_back(nums[i]);
            RecursiveCheck(i + 1, nums, result, currentSet);
            currentSet.pop_back();
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1,2,3 };
    s.subsets(nums);
    return 0;
}