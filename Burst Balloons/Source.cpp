#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxCoins(vector<int>& nums) 
    {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n = nums.size();
        // store max coins between i and j
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // start from minimum subarray length 2
        for (size_t len = 2; len < n; ++len)
        {
            // set left boundary
            for (size_t left = 0; left < n - len; left++)
            {
                int right = left + len;
                // choose last balloon to pop (k)
                for (size_t k = left + 1; k < right; ++k)
                {
                    dp[left][right] = max(dp[left][right], (dp[left][k] + dp[k][right]) + (nums[left] * nums[k] * nums[right]));
                }
            }
        }
        return dp[0][n-1];


    }
};


int main()
{
    Solution s;
    vector<int> nums = { 3,1,5,8 };
    s.maxCoins(nums);


    return 0;
}