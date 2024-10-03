#include <iostream>
using namespace std;

class Solution 
{
public:
    bool isMatch(string s, string p) 
    {
        int stringPtr = 0;
        int patternPtr = 0;
        int asteriskPosStr = 0;
        int asteriskPosPat = -1;

        while (stringPtr < s.size())
        {

            // if normal match
            if (patternPtr < p.size() && (s[stringPtr] == p[patternPtr] || p[patternPtr] == '?'))
            {
                ++patternPtr;
                ++stringPtr;
            }
            // store asterisk pos from both inputs
            else if (patternPtr < p.size() && p[patternPtr] == '*')
            {
                asteriskPosStr = stringPtr;
                // start matching 0 characters at first, then increase until valid (if possible)
                asteriskPosPat = patternPtr++;

                
            }
            // backtrack, consume more characters if no match
            else if (asteriskPosPat != -1)
            {
                patternPtr = asteriskPosPat + 1;
                stringPtr = ++asteriskPosStr;

            }
            else
            {
                return false;
            }
        }


        while (patternPtr < p.size() && p[patternPtr] == '*')
        {
            ++patternPtr;
        }

        return (patternPtr == p.size());
    }



};


int main()
{
    Solution s;
    cout << s.isMatch("aa", "*");
    return 0;
}