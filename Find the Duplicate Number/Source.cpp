#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    int findDuplicate(vector<int>& nums)
    {
        int hare = 0, tortoise = 0;

        // find intersection
        do
        {
            hare = nums[hare];
            tortoise = nums[nums[tortoise]];

        } while (hare != tortoise);

        int hare2 = 0;

        do
        {
            hare = nums[hare];
            hare2 = nums[hare2];


        } while (hare != hare2);

        return hare;


    }
};


int main()
{
    Solution s;
    vector<int> nums = { 1,3,4,2,2 };
    cout << s.findDuplicate(nums);
    return 0;
}