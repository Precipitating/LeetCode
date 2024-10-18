#include <iostream>
#include <vector>
using namespace std;


class Solution
{
public:
    vector<int> sortArray(vector<int>& nums) 
    {
        MergeSort(0,nums.size() - 1, nums);

        return nums;

    }

    void MergeSort(int start, int end, vector<int>& nums)
    {
        if (start >= end) { return; }
        int mid = start + (end - start) / 2;

        MergeSort(start, mid, nums);
        MergeSort(mid+1, end, nums);
        Merge(start, mid, end, nums);

    }

    void Merge(int start, int mid, int end, vector<int>& nums)
    {

        // create two temp vector to store merged array
        vector<int> temp;
        int i = start, j = mid + 1;

        while (i <= mid && j <= end)
        {
            // take left half elem
            if (nums[i] >= nums[j])
            {
                temp.push_back(nums[j++]);
            }
            else
            {
                temp.push_back(nums[i++]);
            }
        }

        while (i <= mid)
        {
            temp.push_back(nums[i++]);
        }
        while (j <= end)
        {
            temp.push_back(nums[j++]);
        }

        for (int k = start; k <= end; ++k)
        {
            nums[k] = temp[k - start];
        }
    }
};


int main()
{
    Solution s;
    vector<int> nums = {5, 2, 3, 1};
    s.sortArray(nums);
    return 0;
}