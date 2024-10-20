#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff)
    {
        vector<int> transformed(nums1.size());
        // simplify equation
        for (size_t i = 0; i < nums1.size(); ++i)
        {
            transformed[i] = nums1[i] - nums2[i];
        }

        MergeSort(0, transformed.size() - 1, transformed, diff);

        return result;
    }

    void MergeSort(int start, int end, vector<int>& transformed, int diff)
    {
        if (start >= end) { return; }

        int mid = start + (end - start) / 2;
        MergeSort(start, mid, transformed, diff);
        MergeSort(mid + 1, end, transformed, diff);
        Merge(start, mid, end, transformed, diff);
        
    }


    void Merge(int start, int mid, int end, vector<int>& transformed, int diff)
    {
        vector<int> temp(end - start + 1);
        int i = start, j = mid + 1, idx = 0;

        while (i <= mid && j <= end)
        {
            if (transformed[i] <= transformed[j] + diff)
            {
                result += end - j + 1;
                ++i;
            }
            else
            {
                ++j;
            }
        }

        i = start, j = mid + 1;

        // merge to temp

        while (i <= mid && j <= end)
        {
            if (transformed[i] <= transformed[j])
            {
                temp[idx++] = transformed[i++];
            }
            else
            {
                temp[idx++] = transformed[j++];
            }
        }

        // get the remaining nums from left & right half

        while (i <= mid)
        {
            temp[idx++] = transformed[i++];
        }
        while (j <= end)
        {
            temp[idx++] = transformed[j++];
        }

        // merge to original array

        for (int k = start; k <= end; ++k)
        {
            transformed[k] = temp[k - start];
        }

    }
private:
    long long result = 0;
};

int main()
{
    Solution s;
    vector<int> nums = { 3,2,5 };
    vector<int> nums2 = { 2,2,1 };
    cout << s.numberOfPairs(nums, nums2, 1);

    return 0;
}