#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        int n = nums1.size(), n1 = nums2.size();
        vector<int> result;
        for (int i = max(0, k - n1); i <= min(k,n); ++i)
        {
            result = max(result, Merge(MaxNumber(nums1, i), MaxNumber(nums2, k - i)));
        }

        return result;
    }

    // extract largest number from single array
    vector<int> MaxNumber(const vector<int>& nums, int k)
    {
        int n = nums.size() - k;
        vector<int> stack;

        for (int num : nums)
        {
            while (n > 0 && !stack.empty() && stack.back() < num)
            {
                stack.pop_back();
                --n;
            }
            stack.push_back(num);
        }

        stack.resize(k);

        return stack;


    }

    vector<int> Merge(vector<int> nums, vector<int> nums2)
    {
        vector<int> result;

        while (nums.size() + nums2.size())
        {
            // lexicographical comparison
            vector<int>& curr = nums > nums2 ? nums : nums2;
            result.push_back(curr[0]);
            // pop front
            curr.erase(curr.begin());
        }

        return result;


    }
};

int main()
{
    Solution s;
    vector<int> nums = { 6,7 };
    vector<int> nums1 = { 6,0,4 };
    s.maxNumber(nums, nums1, 5);
    return 0;
}