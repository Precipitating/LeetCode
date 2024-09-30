#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int>& nums)
    {
        int result = 0;
        bool found = false;

        // place numbers to its index position - 1 (accounting for idx 0)
        for (size_t i = 0; i < nums.size(); ++i)
        {
            int& num = nums[i];

            while (num >= 1 && num < nums.size() && num != nums[nums[i] - 1])
            {
                swap(num, nums[nums[i] - 1]);
            }


        }

        // get the missing consequetive number
        for (size_t i = 0; i < nums.size() && !found; ++i)
        {
            if (nums[i] != i + 1)
            {
                result = i+1;
                found = true;
            }
        }

        return found ? result : nums.size() + 1;
    }
};


int main()
{
    Solution s;
    vector<int> nums = { 1 };
    cout << s.firstMissingPositive(nums);
    return 0;
}