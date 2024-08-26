#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        vector<int> answer;
        answer.reserve(2);
        int first = 0, last = nums.size() - 1;
        int idx = -1;
        // get start
        while (first <= last)
        {

            int half = first + ((last - first) / 2);

            if (nums[half] > target)
            {
                last = half - 1;
            }
            else if (nums[half] < target)
            {
                first = half + 1;
            }
            else
            {
                idx = half;
                last = half - 1;
            }


        }
        answer.push_back(idx);

        first = 0, last = nums.size() - 1;
        // get end
        while (first <= last)
        {

            int half = first + ((last - first) / 2);

            if (nums[half] > target)
            {
                last = half - 1;
            }
            else if (nums[half] < target)
            {
                first = half + 1;
            }
            else
            {
                idx = half;
                first = half + 1;
            }


        }
        answer.push_back(idx);


        if (answer.empty()) { return { -1,-1 }; }
        return answer;
    }

};


int main()
{
    Solution s;
    vector<int> nums = { 5,7,7,8,8,10 };
    s.searchRange(nums,8);
}