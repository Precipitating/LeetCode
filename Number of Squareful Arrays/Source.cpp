#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution
{
public:
    int numSquarefulPerms(vector<int>& nums) 
    {
        int result = 0;
        // handle dupes
        sort(nums.begin(), nums.end());
        int count = 0;
        vector<bool> visited(nums.size());

        BackTrack(-1, 0, nums, visited, result);




        return result;
    }

    void BackTrack(int prev, int len, const vector<int>& nums, vector<bool>& visited, int &result)
    {
        if (len == nums.size()) { ++result; return; }


        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (visited[i] || (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]))
            {
                continue;
            }

            if (prev == -1 || IsPerfectSquare(nums[prev] + nums[i]) )
            {
                visited[i] = true;
                BackTrack(i, len + 1, nums, visited, result);
                visited[i] = false;
            }

        }


    }

    bool IsPerfectSquare(int num)
    {
        int root = sqrt(num);
        return ((root * root) == num);
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1,17,8 };
    s.numSquarefulPerms(nums);
    return 0;
}