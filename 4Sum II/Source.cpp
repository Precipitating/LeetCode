#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution 
{
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) 
    {
        int result = 0;
        // cache num1 and num2 sums
        unordered_map<int, int> sumMap;
        for (int num1 : nums1)
        {
            for (int num2 : nums2)
            {
                ++sumMap[num1 + num2];
            }
        }

        // check if sum of num3 and num4's negation number exists in map
        // if so, add its count 

        for (int num3 : nums3)
        {
            for (int num4 : nums4)
            {
                int negatedSum = -(num3 + num4);
                if (sumMap.find(negatedSum) != sumMap.end())
                {
                    result += sumMap[negatedSum];
                }
                
            }
        }


        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = { 1,2 };
    vector<int> nums2 = { -2,-1 };
    vector<int> nums3 = { -1,2 };
    vector<int> nums4 = { 0,2 };
    cout << s.fourSumCount(nums1, nums2, nums3, nums4);


    return 0;
}