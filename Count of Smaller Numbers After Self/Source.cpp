#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> countSmaller(vector<int>& nums)
    {
        vector<int> result(nums.size(), 0);
        vector<pair<int, int>> idxNums(nums.size());

        // store val & idx
        for (int i = 0; i < nums.size(); ++i)
        {
            idxNums[i] = { nums[i], i };

        }

        MergeSort(0, nums.size() - 1, idxNums, result);

        return result;
        

    }

    void MergeSort(int first, int last, vector<pair<int,int>>& nums, vector<int>& result)
    {
        if (first >= last) { return; }

        int mid = first + (last - first) / 2;
        // left side
        MergeSort(first, mid, nums, result);
        // right side
        MergeSort(mid + 1, last, nums, result);
        Merge(first, mid, last, nums, result);
    }

    void Merge(int first, int mid, int last, vector<pair<int, int>>& nums, vector<int>& result)
    {
        // store temp sorted result after merge
        vector<pair<int,int>> temp(last - first + 1);
        int left = first;
        int right = mid+1;
        int tempIdx = 0;
        // count of right half elements < curr left elem
        int rightCount = 0;

        while (left <= mid && right <= last)
        {
            // if right is smaller than left, increment rightCount and place in temp
            if (nums[right].first < nums[left].first)
            {
                temp[tempIdx++] = nums[right++];
                ++rightCount;
            }
            else
            {
                // add smaller element to result
                result[nums[left].second] += rightCount;
                temp[tempIdx++] = nums[left++];
            }
        }

        while (left <= mid)
        {
            result[nums[left].second] += rightCount;
            temp[tempIdx++] = nums[left++];
        }
        while (right <= last)
        {
            temp[tempIdx++] = nums[right++];
        }

        for (int i = first; i <= last; ++i) 
        {
            nums[i] = temp[i - first];
        }

    }
};


int main()
{
    Solution s;
    vector<int> nums = { 5,2,6,1 };
    s.countSmaller(nums);
}