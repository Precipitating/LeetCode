#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        if (numerator == 0) { return "0"; }
        unordered_map<long long, int> map;
        bool isNeg = (numerator < 0) ^ (denominator < 0);
        string result;
        
        if (isNeg) { result.append("-"); }
        numerator = abs(numerator);
        denominator = abs(denominator);

        // get the whole number only
        long long division = numerator / denominator;
        result.append(to_string(division));

        // if whole number, no decimal so return result early
        long long remainder = (numerator % denominator);
        if ( remainder == 0) { return result; }

        // else theres a decimal, handle it
        result.append(".");
        while (remainder != 0)
        {
            // if remainder was seen before, it means its repeating.
            // we store positions of each remainder, so insert ( at that pos
            // and append )
            if (map.find(remainder) != map.end())
            {
                result.insert(map[remainder], "(");
                result.append(")");
                break;
            }

            map[remainder] = result.size();

            remainder *= 10;
            result.append(to_string(remainder / denominator));
            remainder %= denominator;


        }

 
        return result;
    }


};

int main()
{
    Solution s;
    cout << s.fractionToDecimal(4, 333);

    return 0;
}