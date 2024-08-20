#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // o(N), left ptr is where none zero numbers should be placed
    // right ptr is used to find those none zeros to swap to first
    void moveZeroes(vector<int>& nums)
    {
        int first = 0, last = 0;

        while (last < nums.size())
        {
            if (nums[last] != 0)
            {
                swap(nums[first], nums[last]);
                ++first;

            }
            ++last;
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1,0,1 };
    s.moveZeroes(nums);

	return 0;
}