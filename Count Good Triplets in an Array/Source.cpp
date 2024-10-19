#include <iostream>
#include <vector>
using namespace std;
class FenwickTree
{
public:
    FenwickTree(int size)
    {
        n = size;
        bit.resize(n + 1, 0);
    }


    void Update(int idx, int val)
    {
        while (idx <= n)
        {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }
    
    long long Sum(int idx)
    {
        long long sum = 0;
        while (idx > 0)
        {
            sum += bit[idx];
            idx -= idx & -idx;
        }

        return sum;
    }



private:
    vector<long long> bit;
    int n;

};
class Solution 
{
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2)
    {
        long long result = 0;
        // map positions of elements in both nums1 and 2
        // to get quick access
        vector<int> pos2(nums1.size());
        for (size_t i = 0; i < nums1.size(); ++i)
        {
            pos2[nums2[i]] = i;
        }

        // 2 fenwick trees,
        // b1 used to count valid pairs that can form triplets
        // b2 used to count valid triplets that can be formed from b1

        FenwickTree b1(nums1.size()), b2(nums1.size());
        
        // process nums1 in order
        for (size_t i = 0; i < nums1.size(); ++i)
        {
            // 1 indexed
            int num2Idx = pos2[nums1[i]] + 1;

            // find valid triplets 
            result += b2.Sum(num2Idx - 1);

            // find valid pairs
            int validPair = b1.Sum(num2Idx - 1);

            b2.Update(num2Idx, validPair);

            // mark element as valid pair
            b1.Update(num2Idx, 1);


        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = { 4,0,1,3,2 };
    vector<int> nums2 = { 4,1,0,2,3 };
    s.goodTriplets(nums1, nums2);
    return 0;
}