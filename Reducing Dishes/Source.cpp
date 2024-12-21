#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    int maxSatisfaction(vector<int>& satisfaction)
    {
        sort(satisfaction.rbegin(), satisfaction.rend());
        vector<int> dp(satisfaction.size());
        int sum = 0;
        int result = 0;

        for (size_t i = 0; i < satisfaction.size(); ++i)
        {
            sum += satisfaction[i];
            if (sum < 0) { break; }
            result += sum;

        }

        return result;


    }
};

int main()
{
    Solution s;
    vector<int> sat = { -1,-8,0,5,-7 };
    s.maxSatisfaction(sat);

    return 0;
}
