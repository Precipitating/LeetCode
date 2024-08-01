#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        double result = 0;
        vector<int> sorted(nums1.size() + nums2.size());
        int i = 0;
        int j = 0;
        int sortIdx = 0;

        if (nums1.size() == 0)
        {
            sorted = nums2;
        }
        else if (nums2.size() == 0)
        {
            sorted = nums1;
        }
        else if (nums1.size() == 0 && nums2.size() == 0)
        {
            return 0;
        }
        else
        {
            while (i <= nums1.size() - 1 || j <= nums2.size() - 1)
            {
                // compare both vecs and insert lowest
                if (i < nums1.size() && j < nums2.size())
                {
                    if (nums1[i] <= nums2[j])
                    {
                        sorted[sortIdx] = nums1[i];
                        ++i;
                    }
                    else
                    {
                        sorted[sortIdx] = nums2[j];
                        ++j;
                    }

                }

                else if (i == nums1.size())
                {
                    sorted[sortIdx] = nums2[j];
                    ++j;

                }
                else
                {
                    sorted[sortIdx] = nums1[i];
                    ++i;
                }
                ++sortIdx;;



            }
        }



        // even
        if (sorted.size() % 2 == 0)
        {
            int lowerBoundMiddle = sorted[(sorted.size() / 2) - 1];
            int upperBoundMiddle = sorted[(sorted.size() / 2)];
            result = (double)(lowerBoundMiddle + upperBoundMiddle) / 2;
        }
        else
        {
            result = sorted[sorted.size() / 2];
        }




        return result;




    }
};


int main()
{
    Solution s;
    vector<int> one = {};
    vector<int> two = {3,4 };
    s.findMedianSortedArrays(one, two);

    return 0;
}