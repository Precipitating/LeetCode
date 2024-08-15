#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // A = 1, Z = 26, AA = 27, // ZY = 701
    int titleToNumber(string columnTitle)
    {
        int stringLength = columnTitle.length() - 1;
        int result = 0;

        for (const char& letter : columnTitle)
        {
            char toLower = tolower(letter);
            int toDecimal = (toLower - 'a') + 1;
            result += (toDecimal * pow(26,stringLength));
            --stringLength;
        }

        return result;
    }
};

int main()
{
    Solution s;

    cout << s.titleToNumber("ZYZ");
}