#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // solution 1, simple, not efficient though.
    //void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    //{
    //    vector<int> result;
    //    result.reserve(m + n);
    //    result = {nums1.begin(), nums1.begin() + m};
    //    result.insert(result.end(),nums2.begin(), nums2.begin() + n );
    //    sort(result.begin(), result.end());

    //    nums1 = result;


    //}


    // solution 2 - two pointer O(m+n)
    // iterate from back of nums1 and place the biggest num from both containers.
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        if (m == 0)
        {
            nums1 = nums2;
        }

        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;


        // go thru nums2
        while (j >= 0)
        {
            // go from end to front of vector <---

            if (i >= 0 && nums1[i] > nums2[j])
            {
                nums1[k] = nums1[i];
                --i;

            }
            else
            {
                nums1[k] = nums2[j];
                --j;
            }

            --k;

        }


    }
};

int main()
{
    vector<int> first = {};
    vector<int> second = { 1 };
    Solution s;
    s.merge(first, 0, second, 1);
}