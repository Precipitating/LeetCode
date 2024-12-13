#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    int integerReplacement(long n) 
    {
        int result = 0;

        while (n != 1)
        {
            // half number if even
            // checks if LSB is active, which always makes it odd if its 1
            if ((n & 1) == 0)
            {
                // its even so half it
                n >>= 1;

            }
            // its odd then, so check +1 or -1 depending on the best option
            else
            {
                // if next num is even if halved or 3, -1
                if (n == 3 || (((n >> 1) & 1) == 0))
                {
                    --n;

                }
                else
                {
                    ++n;
                }
            }
            ++result;
        }

        return result;
    }


private:
    int result = 0;

};

int main()
{
    Solution s;
    s.integerReplacement(7);
    return 0;
}