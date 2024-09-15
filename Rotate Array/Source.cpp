#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void rotate(vector<int>& nums, int k)
    {
        k %= nums.size();

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());



    }
};


int main()
{
    Solution s;
    vector<int> nums = { 1,2};
    // 5,6,7,1,2,3,4
    s.rotate(nums,5);
    return 0;
}