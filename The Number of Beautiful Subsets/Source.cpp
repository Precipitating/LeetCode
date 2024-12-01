#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution 
{
public:
    int beautifulSubsets(vector<int>& nums, int k)
    {
        int result = 0;
        Solve(0,nums, k, result);
        return result;
    }

    void Solve(int idx, const vector<int>& nums, int k, int& result)
    {
        if (idx == nums.size())
        {
            ++result;
            return;
        }


        // do nothing and go next
        Solve(idx + 1, nums, k, result);

        // add and go next
        if (map[nums[idx]-k] == 0 && map[nums[idx]+k] == 0)
        {
            ++map[nums[idx]];
            Solve(idx + 1, nums, k, result);
            --map[nums[idx]];

        }
    }

private:
    unordered_map<int, int> map;
};


int main()
{
    Solution s;
    vector<int> nums = { 4,2,5,9,10,3 };

    s.beautifulSubsets(nums, 1);

    return 0;
}