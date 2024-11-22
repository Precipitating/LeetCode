#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<string> ambiguousCoordinates(string s)
    {
        vector<string> result;
        s = s.substr(1, s.size() - 2);

        for (size_t i = 1; i < s.size(); ++i)
        {
            vector<string> firstNum = Solve(s.substr(0, i));
            vector<string> secondNum = Solve(s.substr(i));

            for (const string& first : firstNum)
            {
                for (const string& second : secondNum)
                {
                    result.push_back('(' + first + ", " + second + ')');
                }
            }
        }

        return result;
    }

    vector<string> Solve(string num)
    {
        vector<string> result;

        // single character nums valid
        if (num.size() == 1) { return { num }; }

        // no leading zeroes
        if (num[0] != '0') { result.push_back(num); }

        // handle leading zeroes with decimals
        if (num[0] == '0')
        {
            // simplified numbers only
            if (num.back() == '0') { return {}; }

            return { "0." + num.substr(1) }; // 0.xxx

        }

        // add decimals for every valid number without trailing zeroes
        for (size_t i = 1; i < num.size(); ++i)
        {
            // no trailing
            if (num.substr(i).back() == '0') { continue; }
            result.push_back(num.substr(0, i) + '.' + num.substr(i));
        }
        return result;


    }

};

int main()
{
    Solution s;
    s.ambiguousCoordinates("(0123)");
    return 0;
}