#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        vector<int> result;
        deque<int> deq;

        for (int i = 0; i < nums.size(); ++i)
        {
            int cur = nums[i];
            // remove front if window is out of bounds
            if (!deq.empty() && deq.front() == i - k) { deq.pop_front(); }


            // remove all elements in deq < cur
            while (!deq.empty() && nums[deq.back()] < cur )
            {
                deq.pop_back();
            }

            deq.push_back(i);

            if (i >= k - 1)
            {
                result.push_back(nums[deq.front()]);
            }





        }



        return result;
    }
};


int main()
{
    Solution s;
    vector<int> nums = { 1,3,-1,-3,5,3,6,7 };
    s.maxSlidingWindow(nums, 3);
    return 0;
}
