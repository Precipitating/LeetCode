#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int profit = 0;
        int currentProfit = 0;
        int currentBuy = prices[0];

        for (int i = 1; i < prices.size(); ++i)
        {
            int potentialProfit = prices[i] - currentBuy;
            profit = max(profit, profit + potentialProfit);
            currentBuy = prices[i];



        }

        return profit;
    }
};

int main()
{
    Solution s;
    vector<int> prices = { 7,1,5,3,6,4 };

    s.maxProfit(prices);

    return 0;
}