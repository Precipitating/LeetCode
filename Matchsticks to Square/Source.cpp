#include <iostream>
#include <vector>
#include <algorithm>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool makesquare(vector<int>& matchsticks)
    {
        if (matchsticks.size() < 4) { return false; }
        vector<int> squareFitter(4, 0);

        int maxPossibleNumber = 0;
        for (int num : matchsticks)
        {
            maxPossibleNumber += num;
        }

        if ((maxPossibleNumber % 4) != 0) { return false; }
        sort(matchsticks.rbegin(), matchsticks.rend());

        Solve(0, maxPossibleNumber / 4, squareFitter, matchsticks);

        return result;

    }

    void Solve(int idx, int maxNum, vector<int>& squareFitter, vector<int>& match)
    {
        if (result) { return; }
        if (idx == match.size())
        {
            if (all_of(squareFitter.begin(), squareFitter.end(), [&](int x) {return x == squareFitter[0]; }))
            {
                result = true;
            }

            return;
        }

        for (size_t i = 0; i < 4; ++i)
        {
            if (squareFitter[i] + match[idx] > maxNum) { continue; }
            squareFitter[i] += match[idx];
            Solve(idx + 1, maxNum, squareFitter, match);
            squareFitter[i] -= match[idx];

        }


    }

private:
    bool result = false;
};

int main()
{
    Solution s;
    vector<int> match = { 3,3,3,3,4 };
    s.makesquare(match);
    return 0;
}