#include <iostream>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        double result = x;
        if (n == 0) { return 1; }
        if (n < 0) { x = 1 / x; }

        // ensure n is always positive
        n = abs(n);
        double power = 1;
        while (n != 0)
        {
            // if bit is odd. multiply with power
            if ((n & 1) != 0)
            {
                power *= x;
            }

            x *= x;

            // half n
            n >>= 1;
        }

        return power;
        // if neg its 1/x^n


    }
};


int main()
{
    Solution s;
    s.myPow(2.0, 10);
    return 0;
}