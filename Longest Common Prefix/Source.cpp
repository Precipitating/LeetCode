#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {

        // its the only possible prefix if its 1
        if (strs.size() == 1)
        {
            return strs.front();
        }

        // if every word is same, return first element string
        if (adjacent_find(strs.begin(), strs.end(), not_equal_to<>()) == strs.end())
        {
            return strs.front();
        }



        // current substring len
        int length = 1;
        for (size_t i = 0; i < strs[0].size(); ++i)
        {
            // if current prefix matches all other other strings, increase length.
            if (FullMatch(strs, length))
            {
                // if its same size as first string, we cant go further so it must be the max prefix.
                if (length == strs[0].size())
                {
                    return strs[0].substr(0, length);
                }

                ++length;

            }
            else
            {
                // if it's 1, then the 2nd element in vector does not match the first at all,
                //  making the whole thing invalid as there must be a common prefix for all elements.
                if (length == 1)
                {
                    return "";
                }

                // return the max prefix.
                return strs[0].substr(0, length - 1);
            }
        }

    }

    // compare the first string substring with all the other strings
    // return true if every other string matches current substring
    // else one string doesn't match the current prefix,  
    bool FullMatch(const vector<string>& strs, int& length)
    {
        bool result = false;

        string firstWord = strs[0];
        for (size_t i = 1; i < strs.size(); ++i)
        {
            if (firstWord.substr(0, length) == strs[i].substr(0, length))
            {
                if (i == strs.size() - 1)
                {
                    return true;
                }

            }
            else
            {

                return false;

            }

        }


        return result;



    }




};

int main()
{
    vector<string> words = { "ab","abcdefg" };
    Solution s;
    cout << s.longestCommonPrefix(words);

    return 0;

}