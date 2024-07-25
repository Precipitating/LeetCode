#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if (strs.size() == 1)
        {
            return strs.front();
        }

        if (adjacent_find(strs.begin(), strs.end(), not_equal_to<>()) == strs.end())
        {
            return strs.front();
        }




        int length = 1;
        for (size_t i = 0; i < strs[0].size(); ++i)
        {
            if (FullMatch(strs, length))
            {
                if (length == strs[0].size())
                {
                    return strs[0].substr(0, length);
                }
                ++length;

            }
            else
            {
                if (length == 1)
                {
                    return "";
                }

                return strs[0].substr(0, length - 1);
            }
        }

    }

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
    vector<string> words = { "abb","abc" };
    Solution s;
    cout << s.longestCommonPrefix(words);

    return 0;

}