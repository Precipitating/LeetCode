#include <iostream>
#include <string>
using namespace std;


class Solution
{
public:
    bool isPalindrome(string s)
    {
        if (s.empty()) { return true; }
        bool result = true;
        int first = 0;
        int last = s.size() - 1;


        while (last > first)
        {
            if (isalnum(s[last]) && isalnum(s[first]))
            {

                if (tolower(s[first]) != tolower(s[last]))
                {
                    result = false;
                    break;
                    
                }
                ++first;
                --last;

            }
            else if (!isalnum(s[last]))
            {
                --last;
            }
            else
            {
                ++first;
            }

        }

        return result;
    }

};


int main()
{
    Solution s;
    cout << s.isPalindrome("0P");

    return 0;
}