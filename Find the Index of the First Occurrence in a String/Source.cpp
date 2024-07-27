#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    // solution 1, not very fast 
    //int strStr(string haystack, string needle)
    //{
    //    size_t foundPos = haystack.find(needle);
    //    if (foundPos != string::npos)
    //    {
    //        return foundPos;
    //    }
    //    else
    //    {
    //        return -1;
    //    }
    //}

    // solution 2, searching substrings
    int strStr(string haystack, string needle)
    {
        // impossible if one string is empty
        if (haystack.empty() || needle.empty())
        {
            return -1;
        }

        // impossible if needle length is higher than haystack
        if (needle.length() > haystack.length())
        {
            return -1;
        }

        size_t needleLength = needle.length();

        for (int i = 0; i < haystack.length(); ++i)
        {
            if (haystack[i] == needle[0])
            {
                if (haystack.substr(i, needleLength) == needle)
                {
                    return i;
                }
            }
        }

        return -1;

    }

};

int main()
{
    Solution s;
    s.strStr("sadbutsad", "sad");

    return 0;
}
