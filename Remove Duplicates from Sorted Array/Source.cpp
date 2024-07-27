#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution
{
public:
    // solution 1, using STL
    //int removeDuplicates(vector<int>& nums)
    //{
    //    int same = 0;

    //    auto last = unique(nums.begin(), nums.end());



    //    return std::distance(nums.begin(), last);

    //}

    // sol 2, faster
    // check prev, and if not same number it's not ordered.
    int removeDuplicates(vector<int>& nums)
    {
        int unique = 1;
        int j = 1;

        for (size_t i = 1; i < nums.size(); ++i)
        {
            if (nums[i] != nums[i - 1])
            {
                nums[j] = nums[i];
                ++j;
                ++unique;
            }
        }


        return unique;


    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1,1,2,3,3,4};
    int k = s.removeDuplicates(nums);

	return 0;
}