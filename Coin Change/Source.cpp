#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i < (amount + 1); ++i)
        {
            for (const int& coin : coins)
            {
                if ((i - coin) >= 0)
                {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }


        return (dp[amount] != amount + 1) ? dp[amount] : -1;

    }
};


int main()
{
    Solution s;
    vector<int> coins = { 1,2,5 };
    cout << s.coinChange(coins, 11);

    return 0;
}