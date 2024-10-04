#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int answer = 0;
        stack<int> heightStack;
        for (size_t i = 0; i < heights.size(); ++i)
        {
            while (!heightStack.empty() && heights[i] < heights[heightStack.top()])
            {
                int stackHeight = heights[heightStack.top()]; heightStack.pop();
                int width = (heightStack.empty()) ? i : (i - heightStack.top()) - 1;
                answer = max(answer, stackHeight * width);
            }
            heightStack.push(i);
        }

        // process remaining stack values that made it way to the end

        while (!heightStack.empty())
        {
            int stackHeight = heights[heightStack.top()]; heightStack.pop();
            int width = (heightStack.empty()) ? heights.size() : (heights.size() - heightStack.top()) - 1;
            answer = max(answer, stackHeight * width);
        }


        return answer;
    }
};


int main()
{
    Solution s;
    vector<int> heights = { 2,1,5,6,2,3 };
    cout << s.largestRectangleArea(heights);
    return 0;
}