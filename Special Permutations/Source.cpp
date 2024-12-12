#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int Solve(int prevIdx, int currIdx, int mask, vector<int>& nums, vector<vector<int>>& dp)
    {
        if (currIdx == nums.size()) { return 1; }
        // already calculated so dont bother recalulating
        if (dp[prevIdx + 1][mask] != -1) { return dp[prevIdx + 1][mask]; }

        int total = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            // if already visited idx, go next
            if (mask & (1 << i)) { continue; }

            // special permutation condition checks
            if (prevIdx == -1 || nums[prevIdx] % nums[i] == 0 || nums[i] % nums[prevIdx] == 0)
            {
                // set idx to visited via |
                total += Solve(i, currIdx + 1, mask | (1 << i), nums, dp);
                total %= MODULO;
            }
        }

        dp[prevIdx + 1][mask] = total;
        return dp[prevIdx + 1][mask];






    }
    int specialPerm(vector<int>& nums)
    {
        // + 5 to handle potential overflow
        // 1 << 15 used to set enough bits in bitmask to accomodate 0 - 14 idx
        vector<vector<int>> dp(20, vector<int>((1 << 14) + 5, -1));
        return Solve(-1, 0, 0, nums, dp);

    }

private:
    const int MODULO = 1e9 + 7;

};

int main()
{
    Solution s;
    vector<int> nums = { 1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192 };
    s.specialPerm(nums);
    return 0;
}