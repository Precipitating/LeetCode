#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    // hash map O(N+M)
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_map<int,int> intList;
        vector<int> answer;

        for (const int& num : nums1)
        {
            ++intList[num];
        }

        for (const int& num : nums2)
        {
            if (intList[num] > 0)
            {
                answer.push_back(num);
                --intList[num];
            }
                
        }
        
      

        return answer;





    }
};


int main()
{
    Solution s;
    vector<int> nums1 = { 1,2 };
    vector<int> nums2 = { 1,1 };
    s.intersect(nums1, nums2);

    return 0;
}