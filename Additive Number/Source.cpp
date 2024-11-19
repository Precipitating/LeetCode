#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool isAdditiveNumber(string num)
    {
        bool result = false;

        for (size_t i = 1; i <= num.size() / 2; ++i)
        {
            for (size_t j = 1; j <= (num.size() - i) / 2; j++)
            {
                if (Solve(num.substr(0, i), num.substr(i, j), num.substr(i + j)))
                {
                    return true;
                }
            }

        }

        return result;
    }


    bool Solve(const string& first, const string& second, const string& remainder)
    {
        // check for no leading zeroes
        if (first.size() > 1 && first[0] == '0' || second.size() > 1 && second[0] == '0')
        {
            return false;
        }

        // add numbers and convert back to string
        string sum = to_string(stol(first) + stol(second));

        // if true, we at the end of the string
        if (sum == remainder) { return true; }
        else if (remainder.size() <= sum.size() || remainder.substr(0, sum.size()) != sum)
        {
            return false;
        }

        return Solve(second, sum, remainder.substr(sum.size()));



    }
};

int main()
{
    Solution s;
    s.isAdditiveNumber("199100199");
    return 0;
}