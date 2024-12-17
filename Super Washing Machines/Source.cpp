#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution
{
public:
    int findMinMoves(vector<int>& machines)
    {
        int result = 0;
        int total = accumulate(machines.begin(), machines.end(), 0);
        int n = machines.size();

        if ((total % n ) != 0) { return -1; }

        int balancedNum = total / n;
        int right = 0;

        // right being postiive = send clothes to right
        // right being negative = send clothes to left
        for (size_t i = 0; i < n; ++i)
        {
            right = machines[i] + (right - balancedNum);
            result = max(result, max(abs(right), machines[i] - balancedNum));
        }
        return result;

    }
};

int main()
{
    Solution s;
    vector<int> mach = { 1,0,5 };
    s.findMinMoves(mach);
    return 0;
}