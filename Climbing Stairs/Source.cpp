#include <iostream>

using namespace std;

class Solution
{
public:
    // solution using fibonacci sequence (skip first 2)
    int climbStairs(int n)
    {
        // skip first 2 fib nums
        int counter = 1;
        long long finalNum = 0;
        long long prev = 0;
        long long current = 1;
        while (counter  <= n)
        {
            finalNum += prev + current;
            prev = current;
            current = finalNum;

            if (counter != n)
            {
                finalNum = 0;
            }

            ++counter;
        }

        return finalNum;
    }
};
int main()
{
    Solution s;
    cout << s.climbStairs(3);

}