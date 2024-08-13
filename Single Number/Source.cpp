#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    int singleNumber(vector<int>& nums)
    {
        int num = 0;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            num ^= nums[i];
        }

        return num;
    }
};



int main()
{
    Solution s;
    vector<int> nums = { 1,2,1,2,3,4,3,4,5,5,69,6,6};
    cout << s.singleNumber(nums);
    return 0;
}