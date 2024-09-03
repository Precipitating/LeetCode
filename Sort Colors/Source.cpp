#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // count method o(n) (4 pass)
    //void sortColors(vector<int>& nums) 
    //{
    //    int zeroCount = count(nums.begin(), nums.end(), 0);
    //    int oneCount = count(nums.begin(), nums.end(), 1);
    //    int twoCount = count(nums.begin(), nums.end(), 2);
    //    for (size_t i = 0; i < nums.size(); ++i)
    //    {
    //        if (zeroCount != 0)
    //        {
    //            nums[i] = 0;
    //            --zeroCount;
    //        }
    //        else if (oneCount != 0)
    //        {
    //            nums[i] = 1;
    //            --oneCount;
    //        }
    //        else
    //        {
    //            nums[i] = 2;
    //            --twoCount;
    //        }
    //    }

    //}

    // dutch method (1 pass) (o(n)) 
    // mid is used to traverse,
    // idea is to keep all 0's before low
    // and 2's after high
    // if 1, then just go next
    void sortColors(vector<int>& nums)
    {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;


        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[mid], nums[low]);
                ++mid;
                ++low;
            }
            else if (nums[mid] == 1)
            {
                ++mid;
            }
            else
            {
                swap(nums[mid], nums[high]);
                --high;
            }
        }

    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1,1,0,0,1,0,2,1,2 };
    s.sortColors(nums);

    return 0;
}