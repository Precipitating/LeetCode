#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    // O(n) solution
    int majorityElement(vector<int>& nums)
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

        

    }
};
int main()
{
    Solution s;
    vector<int> nums = { 2,2,1,1,1,2,2 };
    cout << s.majorityElement(nums);




	return 0;
}