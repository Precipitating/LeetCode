#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;

class Solution {
public:

    // soluton 1, simple erase remove idiom, not that efficient.
    //int removeElement(vector<int>& nums, int val) 
    //{
    //    nums.erase(remove(nums.begin(), nums.end(), val),nums.end());

    //    return nums.size();

    //}


    // solution 2, move all val numbers to the end of the vector, no erasure.
    int removeElement(vector<int>& nums, int val)
    {
        auto it = std::partition(nums.begin(), nums.end(), [val](int num) {return num != val; });

        nums.resize(distance(nums.begin(), it));

        return nums.size();

    }
};


int main()
{
    Solution s;
    vector<int> nums = { 0,1,2,2,3,0,4,2 };
    int val = 2;
    int k = s.removeElement(nums, val);



    sort(nums.begin(), nums.begin() + k);


    return 0;
}