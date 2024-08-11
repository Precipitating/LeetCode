#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:

    // o(N) solution
    int maxProfit(vector<int>& prices)
    {
        int maxProfit = 0;
        int toCheck = prices[0];
        for (size_t i = 1; i < prices.size(); ++i)
        {
            int next = prices[i];
            if (next > toCheck)
            {
                int potentialProfit = next - toCheck;
                maxProfit = max(maxProfit, potentialProfit);
            }
            else
            {
                toCheck = next;
            }
        }


        return maxProfit;


    }
};


int main()
{
    Solution s;
    vector<int> prices = { 7,1,5,3,6,4 };

    cout << s.maxProfit(prices);

    return 0;
}