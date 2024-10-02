#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int trap(vector<int>& height)
    {
        int result = 0;
        int left = 0, right = height.size() - 1;
        int leftMax = height[0], rightMax = height[right];


        while (left < right)
        {      
            if (leftMax < rightMax)
            { 
                ++left;
                leftMax = max(leftMax,height[left]);
                result += leftMax - height[left];
            }
            else 
            {
                --right;
                rightMax = max(rightMax, height[right]);
                result += rightMax - height[right];
            }

        }

        return result;




    }
};


int main()
{
    Solution s;
    vector<int> nums = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    s.trap(nums);
    return 0;
}