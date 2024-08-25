#include <iostream>
using namespace std;

class Solution 
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT_MIN && divisor == -1) { return INT_MAX; }
        if (dividend == INT_MIN && divisor == 1) { return INT_MIN; }

        bool isNeg = (divisor < 0) ^ (dividend < 0);
        // ensure same signs
        dividend = dividend > 0 ? -dividend : dividend;
        divisor = divisor > 0 ? -divisor : divisor;

        int answer = 0;

        int counter = 1, doubler = divisor;
        // get max number we can subtract from dividend
        while (doubler >= (INT_MIN >> 1) && (dividend <= (doubler + doubler)))
        {
            // double it
            counter <<= 1;
            doubler += doubler;

            
        }
        while (dividend <= divisor)
        {
            if (dividend <= doubler)
            {
                dividend -= doubler;
                answer += counter;
            }

            // half doubler and counter
            doubler >>= 1;
            counter >>= 1;

        }

        if (isNeg)
        {
            answer = -answer;
        }

        return answer;
    }

};

int main()
{
    Solution s;
    cout << s.divide(33, 6);
    return 0;
}