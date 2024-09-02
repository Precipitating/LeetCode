#include <iostream>
#include <vector>
using namespace std;


class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        int result = 0;
        // first column and row is all 1 as we can only go down and right once
        // meaning theres only 1 possible way down/right
        // basically a pascal triangle.
        vector<vector<int>> dp(m, vector<int>(n, 1));

        // starting from coord 1,1: the possible paths of each coord is
        // top + left (opposite of right -> down)
        for (size_t i = 1; i < dp.size(); ++i)
        {
            for (size_t j = 1; j < dp[0].size(); ++j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }


};

int main()
{
    Solution s;
    cout << s.uniquePaths(3, 7);
    return 0;
}