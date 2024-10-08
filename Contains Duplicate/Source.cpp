#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // space & time complexity = o(N)
    //bool containsDuplicate(vector<int>& nums)
    //{
    //    bool result = false;
    //    unordered_set<int> seenValues;
    //    for (size_t i = 0; i < nums.size(); ++i)
    //    {
    //        if (seenValues.count(nums[i]) != 0)
    //        {
    //            result = true;
    //            return result;
    //        }
    //        else
    //        {
    //            seenValues.insert(nums[i]);
    //        }
    //    }
    //    return result;
    //}
    


    // o(n log n), sort and check prev. O(1) space complexity
    bool containsDuplicate(vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());

        for (size_t i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == nums[i - 1])
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    Solution s;
    vector<int> list = { 1,2,2,3,4,5 };
    cout << s.containsDuplicate(list);
    return 0;
}