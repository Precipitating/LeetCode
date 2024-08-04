#include <iostream>
#include <string>
#include <vector>
using namespace std;



class Solution
{
public:
    int reverse(int x)
    {
        bool isNeg = false;
        int result = 0;


        while (x != 0)
        {
            if ( result > INT_MAX / 10 || result < INT_MIN / 10)
            {
                return 0;
            }
            result *= 10;
            result += x % 10;
            x /= 10;



        }

        return result;


       
    }
};


int main()
{
    int x = -2147483412;

    Solution s;

    cout << s.reverse(x);




    return 0;
}