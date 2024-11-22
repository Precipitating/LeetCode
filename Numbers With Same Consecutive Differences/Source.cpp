#include <iostream>
#include <vector>
using namespace std;


class Solution 
{
public:
    vector<int> numsSameConsecDiff(int n, int k)
    {
        vector<int> result;

        for (int i = 1; i < 10; ++i)
        {
            Solve(1, i, n, k, result);
        }


        return result;
    }

    void Solve(int len, int curr, int n, int k, vector<int>& result)
    {
        if (len == n)
        {
            result.push_back(curr);
            return;
        }


        int lastDig = curr % 10;

        // possible digits
        int up = lastDig + k;
        int down = lastDig - k;

        if (up >= 0 && up <= 9)
        {
            Solve(len + 1, (curr * 10) + up, n, k, result);
        }
        if (down >= 0 && down <= 9 && k != 0)
        {
            Solve(len + 1, (curr * 10) + down, n, k, result);
        }


    }
};

int main()
{
    Solution s;
    
    s.numsSameConsecDiff(2, 0);

    return 0;
}