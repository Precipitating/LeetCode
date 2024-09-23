#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        // DP O(n^2) solution
        vector<int> dp(nums.size(),1);

        for (int i = nums.size() - 1; i > -1; --i)
        {
            for (int j = i+1; j < nums.size(); ++j)
            {
                if (nums[i] < nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }

};

int main()
{
    Solution s;
    vector<int> nums = { 0,1,0,3,2,3 };
    cout << s.lengthOfLIS(nums);

    return 0;
}