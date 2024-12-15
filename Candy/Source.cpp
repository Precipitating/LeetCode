#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int candy(vector<int>& ratings) 
    {
        int up = 0, down = 0, peak = 0;
        for (size_t i = 1; i < ratings.size(); ++i)
        {
            if (ratings[i - 1] < ratings[i])
            {
                down = 0;
                ++up;
                peak = up + 1;
                result += peak;
            }
            else if (ratings[i - 1] == ratings[i])
            {
                down = 0;
                up = 0;
                peak = 0;
                ++result;
            }
            else
            {
                ++down;
                up = 0;
                // (peak > down) is either 1 or 0 depending on result
                result += down + 1 - (peak > down);
            }


        }

        return result;
    }

private:
    int result = 1;
};

int main()
{
    Solution s;
    vector<int> nums = { 1,0,2 };
    s.candy(nums);
    return 0;
}