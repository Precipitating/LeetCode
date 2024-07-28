#include <iostream>
#include <string>
using namespace std;




class Solution
{
public:
    // solution 1, simple for loop: Runtime O(N) Space complexity: O(1)
    int lengthOfLastWord(string s)
    {
        int len = 0;

        for (size_t i = s.length() - 1; i != -1; --i)
        {
            if (s[i] != ' ')
            {
                ++len;
            }
            else
            {
                if (len > 0)
                {
                    return len;
                }
            }


        }
       

        return len;
    }

};



int main()
{
    Solution s;
    int x = s.lengthOfLastWord("a");

    cout << x;

    return 0;
}