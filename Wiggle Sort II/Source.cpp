#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    void wiggleSort(vector<int>& nums)
    {
        // find median
        nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
        int median = *(nums.begin() + nums.size() / 2);

        // rewire index so odd indexes first, then even
        #define A(i) nums[(1 + 2*(i)) % (nums.size() | 1)]

        // use double pointers and swap according to:
        // odd should be greater than neighbours
        // even should be less

        int left = 0, right = nums.size() - 1;

        for (int i = 0; i <= right;)
        {
            if (A(i) > median)
            {
                swap(A(i++), A(left++));
            }
            else if (A(i) < median)
            {
                swap(A(i), A(right--));
            }
            else
            {
                ++i;
            }

        }

    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1,3,2,2,3,1 };

    s.wiggleSort(nums);
}