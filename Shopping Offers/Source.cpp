#include <iostream>
#include <vector>
#include <map>
using namespace std;


class Solution
{
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) 
    {
        return Solve(0, price, special, needs);
        

    }

    int Solve(int idx, const vector<int>& price, const vector<vector<int>>& special, const vector<int>& needs)
    {
        // if all special offers checked, purchase remaining items at regular price
        if (idx == special.size())
        {
            int cost = 0;
            for (size_t i = 0; i < needs.size(); ++i)
            {
                cost += needs[i] * price[i];
            }
            return cost;
        }

        // prevent recalculating same problem
        if (mp.find({ idx,needs }) != mp.end()) { return mp[{idx, needs}]; }

        // apply current special offer
        vector<int> need = needs;

        for (size_t i = 0; i < price.size(); ++i)
        {
            need[i] = needs[i] - special[idx][i];
            if (need[i] < 0)
            {
                return mp[{idx, needs}] = Solve(idx + 1, price, special, needs);
            }


        }

        // return lowest of pick or dont pick options
        return mp[{idx,needs}] = min(Solve(idx+1, price, special, needs), Solve(idx, price, special, need) + special[idx][price.size()]);



    }

private:
    map<pair<int, vector<int>>, int> mp;
};

int main()
{
    Solution s;
    vector<int> price = { 2,5 };
    vector<vector<int>> special = { {3,0,5}, {1,2,10} };
    vector<int> needs = { 3,2 };
    s.shoppingOffers(price, special, needs);
    return 0;
}