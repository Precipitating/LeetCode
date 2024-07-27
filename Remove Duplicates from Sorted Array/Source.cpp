#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution
{
public:
    // solution 1, using STL
    int removeDuplicates(vector<int>& nums)
    {
        int same = 0;

        auto last = unique(nums.begin(), nums.end());



        return std::distance(nums.begin(), last);

    }
};

int main()
{
    Solution s;
    vector<int> nums = { 0,0,1,1,1,2,2,3,3,4 };
    int k = s.removeDuplicates(nums);

	return 0;
}