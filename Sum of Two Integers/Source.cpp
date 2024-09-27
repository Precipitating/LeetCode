#include <iostream>
using namespace std;

class Solution 
{
public:
    int getSum(int a, int b)
    {
        int result = 0;
        int remainder = 0;
        for (size_t i = 0; i < 32; ++i)
        {
            // if both 1 in current bit... 
            if ((a & 1) && (b & 1))
            {
                // if no remainder, then set to 0 and add to remainder var
                if (remainder == 0)
                {
                    ++remainder;
                    // set to 0
                    result &= ~(1 << i);
                }
                else
                {
                    result |= (1 << i);

                }
            }
            // if either is 1 
            else if ((a & 1) ^ (b & 1))
            {
                // set bit to 1
                if (remainder == 0)
                {
                    result |= (1 << i);
                }
                else
                {
                    // clear
                    result &= ~(1 << i);
                }
            }
            else
            {
                // both 0 bit

                if (remainder)
                {
                    --remainder;
                    result |= (1 << i);
                }
            }

            // shift right to get next bit
            a >>= 1;
            b >>= 1;
        }

        return result;
    }
};

int main()
{
    Solution s;
    cout << s.getSum(-1, 1);
    return 0;
}