#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int>& nums) 
    {
        int zeroCount = count(nums.begin(), nums.end(), 0);
        int oneCount = count(nums.begin(), nums.end(), 0);
        int twoCount = count(nums.begin(), nums.end(), 0);

        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (zeroCount != 0)
            {
                nums[i] = 0;
                --zeroCount;
            }
            else if (oneCount != 0)
            {
                nums[i] = 1;
                --oneCount;
            }
            else
            {
                nums[i] = 2;
                --twoCount;
            }
        }

    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1 };
    s.sortColors(nums);

    return 0;
}