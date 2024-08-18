#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        int maxArea = 0;
        int first = 0, last = height.size() - 1;

        while (first < last)
        {
            int h = min(height[first], height[last]);
            int w = last - first;
            maxArea = max(maxArea,h * w);
            
            if (height[first] > height[last])
            {
                --last;
            }
            else
            {
                ++first;
            }


        }

        return maxArea;
    }
};



int main()
{
    Solution s;
    vector<int> list = { 2,3,4,5,18,17,6 };
    cout << s.maxArea(list);
    return 0;
}