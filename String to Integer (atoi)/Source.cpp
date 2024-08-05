#include <iostream>
using namespace std;


class Solution
{
public:
    int myAtoi(string s)
    {
        long long result = 0;
        bool isPositive = true;
        bool digitSpotted = false;
        bool hasOverflown = false;
        bool signFound = false;

        for (size_t i = 0; i < s.length(); ++i)
        {
            // edge cases
            if ((s[i] == '+' || s[i] == '-'))
            {

                if (!signFound)
                {
                    signFound = true;
                }
                else
                {
                    break;
                }
                if (s[i] == '-')
                {
                    isPositive = false;
                    
                }

                continue;

            }

            if ((s[i] == ' ' && signFound || s[i] == ' ' && digitSpotted)) break;
            if (s[i] == ' ') { continue; }
            if (!isdigit(s[i]) && !digitSpotted) break;
            if (!isdigit(s[i])) { break; }

            digitSpotted = true;
            int toNum = s[i] - '0';

            result *= 10;
            result += toNum;
            if (result > INT_MAX && isPositive) { return INT_MAX; }
            else if (-result < INT_MIN && !isPositive) { return INT_MIN; }

            if (i + 1 != s.size() && s[i + 1] == '-' || s[i + 1] == '+') { break; }




        }

        if (!isPositive) { result = -result; }



        return result;

    }
};


int main()
{
    Solution s;
    cout << s.myAtoi("-5-");

    return 0;
}