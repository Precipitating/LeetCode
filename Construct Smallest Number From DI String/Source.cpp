#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution
{
public:
    string smallestNumber(string pattern)
    {
        string result;

        int j = 0;

        for (size_t i = 0; i <= pattern.size(); ++i)
        {
            result.push_back('1' + i);
            if (i == pattern.size() || pattern[i] == 'I')
            {
                reverse(result.begin() + j, result.end());
                j = i + 1;
            }
        }

        return result;
    }


};

int main()
{
    Solution s;
    s.smallestNumber("IIIDIDDD");

    return 0;
}