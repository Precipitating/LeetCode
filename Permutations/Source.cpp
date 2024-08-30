#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        if (nums.size() == 1) { return { {nums[0]} }; }

        vector<vector<int>> result;

        RecursivePermutation(nums.size(), nums, result);

        return result;
    }

    void RecursivePermutation(int idx,vector<int>& nums, vector<vector<int>>& result)
    {
        if (idx == 1) { result.push_back(nums); }
        else
        {
            RecursivePermutation(idx - 1, nums, result);
            for (int i = 0; i < idx - 1; ++i)
            {
                if (idx % 2 == 0)
                {
                    swap(nums[i], nums[idx-1]);

                }
                else
                {
                    swap(nums[0], nums[idx-1]);
                }
                RecursivePermutation(idx-1, nums, result);
            }


            
        }




    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1,2,3 };
    s.permute(nums);
}