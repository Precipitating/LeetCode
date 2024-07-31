#include <iostream>
#include <string>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {

        int result = 0;
        int currentLen = 0;
        bool isDupe = false;
        size_t first = 0, last = s.length();
        unordered_set<char> seenValues;

        while (first != last)
        {
            
            // check substring for any dupe characters
            for (size_t i = first; (i < s.length() && !isDupe); ++i)
            {
                if (seenValues.count(s[i]) != 0)
                {
                    isDupe = true;
                }
                else
                {
                    seenValues.insert(s[i]);
                    ++currentLen;
                    

                }
            }

            if (isDupe)
            {
                isDupe = false;
            }
            ++first;
            result = max(result, currentLen);
            currentLen = 0;

            seenValues.clear();
          
        }



        return result;
    }


};


int main()
{



    Solution s;
    cout << s.lengthOfLongestSubstring(" ");
}

