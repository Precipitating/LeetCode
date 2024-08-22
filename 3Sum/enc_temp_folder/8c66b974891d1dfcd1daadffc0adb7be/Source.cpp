#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<int> currentPair(3, 0);
        vector<vector<int>> result;
        int second = 0, last = nums.size() - 1;

        sort(nums.begin(), nums.end());

        for (size_t i = 0; i < nums.size(); ++i)
        {
            // ignore number if same to prevent dupes
            if (i > 0 && nums[i] == nums[i - 1]) { continue; }

            second = i + 1;
            last = nums.size() - 1;

            while (second < last)
            {
                int total = nums[i] + nums[second] + nums[last];
                if (total > 0)
                {
                    --last;
                }
                else if (total < 0)
                {
                    ++second;
                }
                else
                {
                    result.push_back({ nums[i], nums[second], nums[last] });
                    ++second;

                    // if incremented second is same number, keep incrementing to a new number
                    while (nums[second] == nums[second - 1] && second < last)
                    {
                        ++second;
                    }
                }
            }

        }






        return result;
    }
};


int main()
{
    Solution s;
    vector<int> nums = { 0,0,0,0 };
    s.threeSum(nums);
    return 0;
}