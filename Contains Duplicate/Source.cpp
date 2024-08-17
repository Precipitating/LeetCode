#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    // space & time complexity = o(N)
    bool containsDuplicate(vector<int>& nums)
    {
        bool result = false;
        unordered_set<int> seenValues;

        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (seenValues.count(nums[i]) != 0)
            {
                result = true;
                return result;
            }
            else
            {
                seenValues.insert(nums[i]);
            }
        }

        return result;
    }
};

int main()
{
    Solution s;
    vector<int> list = { 1,2,3,4,5 };
    cout << s.containsDuplicate(list);
    return 0;
}