#include <iostream>
#include <vector>
using namespace std;


class Solution
{
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        int first = INT_MAX, second = INT_MAX;

        for (size_t i = 0; i < nums.size(); ++i)
        {
            // get smallest element
            if (nums[i] <= first) { first = nums[i]; }
            // get second smallest element
            else if (nums[i] <= second) { second = nums[i]; }
            // must be 3rd largest, meaning last triplet exists
            else {return true;}

        }

        return false;

    }

};


int main()
{
    Solution s;
    vector<int> nums = { 1,5,0,4,1,3 };

    cout << s.increasingTriplet(nums);

    return 0;
}