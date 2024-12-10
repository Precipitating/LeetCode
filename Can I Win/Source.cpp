#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal)
    {
        dp.resize((1 << maxChoosableInteger), -1);
        // return early if its not possible 
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal)
        {
            return false;
        }

        return Solve(desiredTotal, 0, maxChoosableInteger);

    }

    bool Solve(int total, int mask, int maxNum)
    {
        if (dp[mask] != -1) { return dp[mask]; }

        for (int i = 1; i <= maxNum; ++i)
        {
            // if num used, skip it
            if (mask & (1 << (i - 1))) { continue; }

            // marked visited
            int updatedMask = mask | (1 << (i - 1));

            if (total - i <= 0 || !Solve(total - i, updatedMask, maxNum))
            {
                return dp[mask] = true;
            }

        }
        return dp[mask] = false;

    }

private:
    vector<int> dp;
};

int main()
{
    Solution s;
    s.canIWin(10, 11);

    return 0;
}