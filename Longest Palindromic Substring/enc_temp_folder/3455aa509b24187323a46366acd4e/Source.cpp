#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution
{
public:
    //// first solution, slow O(n^3)
    //string longestPalindrome(string s)
    //{
    //    int potentialFirst = 0;
    //    int potentialLast = 0;
    //    int potentialSize = 0;
    //    int first = 0;
    //    int last = s.size() - 1;
    //    while (first <= last)
    //    {
    //        if (first == last)
    //        {
    //            ++first;
    //            last = s.size() - 1;
    //        }
    //        else
    //        {
    //            if (s[first] == s[last] && s[first + 1] == s[last - 1])
    //            {
    //                string substr = s.substr(first, (last - first) + 1);
    //                if (substr.length() > potentialSize)
    //                {
    //                    if (subStringPalindrome(substr))
    //                    {
    //                        potentialFirst = first;
    //                        potentialLast = last;
    //                        potentialSize = substr.length();
    //                    }
    //                }
    //                --last;
    //            }
    //            else
    //            {
    //                --last;
    //            }
    //        }
    //    }



    //    return s.substr(potentialFirst, potentialLast - (potentialFirst - 1));
    //}
    //bool subStringPalindrome(const string& s)
    //{
    //    int first = 0;
    //    int last = s.size() - 1;
    //    bool isPalindrome = false;
    //    while (first <= last)
    //    {
    //        if (s[first] == s[last])
    //        {
    //            if ((first == last))
    //            {
    //                isPalindrome = true;
    //                first = last + 1;
    //            }
    //            ++first;
    //            if (first == last)
    //            {
    //                isPalindrome = true;
    //            }
    //            --last;
    //        }
    //        else
    //        {
    //            first = last + 1;
    //        }
    //    }
    //    return isPalindrome;
    //}


    // second method, O(n^2) 
    string longestPalindrome(string s)
    {
        string currentPalindrome;
        int currentLength = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            int left = i, right = i;

            // check odd length palindromes
            while (left >= 0 && right < s.length() && s[left] == s[right])
            {

                // if palindrome length is bigger than our current
                // update it.
                if (((right - left) + 1) > currentLength)
                {
                    currentPalindrome = s.substr(left, (right - left) + 1);
                    currentLength = (right - left) + 1;
                }
                // expand outwards
                --left;
                ++right;

                
            }

            left = i;
            right = i + 1;
            // check even length
            while (left >= 0 && right < s.length() && s[left] == s[right])
            {
                // if palindrome length is bigger than our current
                // update it.
                if (((right - left) + 1) > currentLength)
                {
                    currentPalindrome = s.substr(left, (right - left) + 1);
                    currentLength = (right - left) + 1;
                }
                // expand outwards
                --left;
                ++right;

            }
        }

        return currentPalindrome;


    }
};


int main()
{
    Solution s;


    cout << s.longestPalindrome("bruhkayaklel");
    return 0;
}