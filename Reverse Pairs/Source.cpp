#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int reversePairs(vector<int>& nums) 
    {
        return MergeSort(0, nums.size() - 1, nums);
    }


    int MergeSort(int first, int last, vector<int>& nums)
    {
        if (first >= last) { return 0; }
        int mid = first + (last - first) / 2;

        int count = MergeSort(first, mid, nums) + MergeSort(mid+1, last, nums);

        int j = mid + 1;
        for (int i = first; i <= mid; ++i)
        {
            while (j <= last && nums[i] > (2LL * nums[j]))
            {
                ++j;
            }

            count += j - (mid + 1);
        }
        Merge(first, mid, last, nums);

        return count;

    }
    void Merge(int first, int mid, int last, vector<int>& nums)
    {
        // create two temp vector to store merged array
        vector<int> temp;

        int i = first, j = mid + 1;

        while (i <= mid && j <= last)
        {
            // take left half elem
            if (nums[i] <= nums[j])
            {
                temp.push_back(nums[i++]);
            }
            else
            {
                temp.push_back(nums[j++]);
            }
        }

        while (i <= mid)
        {
            temp.push_back(nums[i++]);
        }
        while (j <= last)
        {
            temp.push_back(nums[j++]);
        }

        for (int k = first; k <= last; ++k)
        {
            nums[k] = temp[k - first];
        }


    }

};

int main()
{
    Solution s;
    vector<int> nums = { 1,3,2,3,1 };
    cout << s.reversePairs(nums);
    return 0;
}