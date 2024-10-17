#include <iostream>
#include <vector>
using namespace std;


class Solution
{
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) 
    {
        if (nums.size() == 0) { return 0; }
        // cache prefix sums from nums so we can easily get sums of a range
        vector<long> prefix(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i)
        {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        // merge sort
        return MergeSort(0, nums.size()+1, prefix, lower, upper);



    }
    int MergeSort(int i, int j, vector<long>& prefix, int lower, int upper)
    {
        if (j - i <= 1) { return 0; }
        int mid = i + (j - i) / 2;

        int count = MergeSort(i, mid, prefix, lower, upper) + MergeSort(mid, j, prefix, lower, upper);

        int start = mid, end = mid, t = mid, len = 0;

        vector<long> cache(j - i, 0);

        for (int k = i, r = 0; k < mid; ++k, ++r)
        {
            // count valid sums in range
            while (start < j && prefix[start] - prefix[k] < lower) { ++start; }
            while (end < j && prefix[end] - prefix[k] <= upper) { ++end; }
            count += end - start;

            while (t < j && prefix[t] < prefix[k]) { cache[r++] = prefix[t++]; }
            cache[r] = prefix[k];
            len = r;


        }
        for (int s = 0; s <= len; ++s)
        {
            prefix[i + s] = cache[s];

        }
        return count;
    }

};


int main()
{
    Solution s;
    vector<int> nums = { -2,5,-1 };
    int lower = -2;
    int upper = 2;

    cout << s.countRangeSum(nums, lower, upper);
    return 0;
}