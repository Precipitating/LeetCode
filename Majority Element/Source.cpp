#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    // O(n) solution
    /*int majorityElement(vector<int>& nums)
    {
        int maxVal;
        unordered_map<int, int> seenValues;
        int start = 0, end = nums.size() - 1;

        while (start <= end)
        {
            if (start == end)
            {
                ++seenValues[nums[start]];
            }
            else
            {
                ++seenValues[nums[start]];
                ++seenValues[nums[end]];
            }


            ++start;
            --end;
        }
        pair<int, int> biggestElem;
        for (const auto& it : seenValues)
        {
            if (it.second > biggestElem.second)
            {
                biggestElem = it;
            }

        }
        
        return biggestElem.first;

        

    }*/

    //o(N) time complexity but O(1) space complexity
    // swap result to be current num if count == 0
    // the result will end up being highest because if there is more of it,
    // it will out-increment the other numbers.
    int majorityElement(vector<int>& nums)
    {
        int result = 0, highest = 0;
        for (const int& num : nums)
        {
            if (highest == 0)
            {
                result = num;
            }

            if (num == result)
            {
                ++highest;
            }
            else
            {
                --highest;
            }
        }
        return result;

    }
};
int main()
{
    Solution s;
    vector<int> nums = { 2,2,1,1,1,2,2 };
    cout << s.majorityElement(nums);




	return 0;
}