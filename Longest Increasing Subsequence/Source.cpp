#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        vector<int> dp(nums.size(),1);

        for (int i = nums.size() - 1; i > 0; --i)
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
    vector<int> nums = { 10,9,2,5,3,7,101,18 };
    cout << s.lengthOfLIS(nums);

    return 0;
}