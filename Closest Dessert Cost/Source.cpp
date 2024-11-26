#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target)
    {
        int result = INT_MAX;

        for (size_t i = 0; i < baseCosts.size(); ++i)
        {
            Solve(0, baseCosts[i],toppingCosts, target, result);
        }

        return result;
    }

    void Solve(int idx, int sum, const vector<int>& top, int target, int& result)
    {
        if (abs(target - result) > abs(target - sum))
        {
            result = sum;
        }
        else if (abs(target - result) == abs(sum - target))
        {
            result = min(result, sum);
        }

        if (idx == top.size()) { return; }

        Solve(idx + 1, sum, top, target, result);
        Solve(idx + 1, sum + top[idx], top, target, result);
        Solve(idx + 1, sum + (2*top[idx]), top, target, result);

    }
};

int main()
{
    Solution s;
    vector<int> base = { 1,7 };
    vector<int> topping = { 3,4 };

    s.closestCost(base, topping, 10);
    return 0;
}