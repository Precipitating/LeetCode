#include <iostream>
#include <vector>
using namespace std;
class Solution 
{
public:
    int countNumbersWithUniqueDigits(int n) 
    {
        if (n == 0) { return 1; }

        return BackTrack(n,0);
    }

    int BackTrack(int n, int visited)
    {
        if (n == 0) { return 1; }

        int result = 1;

        for (size_t i = 0; i <= 9; ++i)
        {
            // if current bit is 1 (meaning visited) or i = 0, skip it
            if (i == 0 && visited == 0 || ((visited >> i) & 1) == 1)
            {
                continue;
            }

            // mark visited
            visited |= 1 << i;
            result += BackTrack(n - 1, visited);
            // unvisit
            visited &= ~(1 << i);
        }
        return result;

    }
};

int main()
{
    Solution s;
    cout << s.countNumbersWithUniqueDigits(2);
    return 0;
}