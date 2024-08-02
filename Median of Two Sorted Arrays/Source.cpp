#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:

    // O(M+N) solution, O(LOG(M+N)) is required though.
    //double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    //{
    //    double result = 0;
    //    vector<int> sorted(nums1.size() + nums2.size());
    //    int i = 0;
    //    int j = 0;
    //    int sortIdx = 0;
    //    if (nums1.size() == 0)
    //    {
    //        sorted = nums2;
    //    }
    //    else if (nums2.size() == 0)
    //    {
    //        sorted = nums1;
    //    }
    //    else if (nums1.size() == 0 && nums2.size() == 0)
    //    {
    //        return 0;
    //    }
    //    else
    //    {
    //        while (i <= nums1.size() - 1 || j <= nums2.size() - 1)
    //        {
    //            // compare both vecs and insert lowest
    //            if (i < nums1.size() && j < nums2.size())
    //            {
    //                if (nums1[i] <= nums2[j])
    //                {
    //                    sorted[sortIdx] = nums1[i];
    //                    ++i;
    //                }
    //                else
    //                {
    //                    sorted[sortIdx] = nums2[j];
    //                    ++j;
    //                }
    //            }
    //            else if (i == nums1.size())
    //            {
    //                sorted[sortIdx] = nums2[j];
    //                ++j;
    //            }
    //            else
    //            {
    //                sorted[sortIdx] = nums1[i];
    //                ++i;
    //            }
    //            ++sortIdx;;
    //        }
    //    }
    //    // even
    //    if (sorted.size() % 2 == 0)
    //    {
    //        int lowerBoundMiddle = sorted[(sorted.size() / 2) - 1];
    //        int upperBoundMiddle = sorted[(sorted.size() / 2)];
    //        result = (double)(lowerBoundMiddle + upperBoundMiddle) / 2;
    //    }
    //    else
    //    {
    //        result = sorted[sorted.size() / 2];
    //    }
    //    return result;
    //}

    // Binary search method O(log(m+n))
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int totalSize = nums1.size() + nums2.size();
        int halfTotal = ((totalSize + 1) / 2);
        int left = 0, right = nums1.size();
        // make sure num1 size is smaller than nums2, for consistency and for the algo to work.
        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }


        
        while (left <= right)
        {
            // get middle element of nums1 & nums2
            int mid = (left + right) / 2;
            int mid2 = halfTotal - mid;

            // get max/min elemnents from both vectors
            int l1 = INT_MIN;
            int l2 = INT_MIN;    
            
            int r1 = INT_MAX;
            int r2 = INT_MAX;


            if (mid < nums1.size())
            {
                r1 = nums1[mid];
            }
            if (mid2 < nums2.size())
            {
                r2 = nums2[mid2];
            }
            if (mid - 1 >= 0)
            {
                l1 = nums1[mid - 1];
            }
            if (mid2 - 1 >= 0)
            {
                l2 = nums2[mid2 - 1];
            }

            // we found median values if l1/l2 is less than r1/r2
            if (l1 <= r2 && l2 <= r1)
            {
                // calculate median now, handle odd/even cases

                // odd
                if (totalSize % 2 == 1)
                {   
                    return max(l1, l2);;
                }
                // even
                else
                {
                    return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
                }


            }
            else if (l1 > r2)
            {
                // move left
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }



        }
        
        return 0;




    }


};


int main()
{
    Solution s;
    vector<int> one = {};
    vector<int> two = {1 };
    cout << s.findMedianSortedArrays(one, two);

    return 0;
}