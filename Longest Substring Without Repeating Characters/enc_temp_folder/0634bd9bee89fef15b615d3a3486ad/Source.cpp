#include <iostream>
#include <string>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    // solution 1: O(N^2), gets slower the larger the input.
    //int lengthOfLongestSubstring(string s)
    //{
    //    int result = 0;
    //    int currentLen = 0;
    //    bool isDupe = false;
    //    size_t first = 0;
    //    unordered_set<char> seenValues;
    //    while (first != s.length())
    //    {
    //        
    //        // check substring for any dupe characters
    //        for (size_t i = first; (i < s.length() && !isDupe); ++i)
    //        {
    //            if (seenValues.count(s[i]) != 0)
    //            {
    //                isDupe = true;
    //            }
    //            else
    //            {
    //                seenValues.insert(s[i]);
    //                ++currentLen;
    //                
    //            }
    //        }
    //        if (isDupe)
    //        {
    //            isDupe = false;
    //        }
    //        ++first;
    //        result = max(result, currentLen);
    //        currentLen = 0;
    //        seenValues.clear();
    //      
    //    }
    //    return result;
    //}

    int lengthOfLongestSubstring(string s)
    {
        int result = 0;
        int currentLen = 0;
        int start = 0;
        if (s.length() == 0)
        {
            return 0;
        }

        vector<int> seen(256, -1);

        for (int end = 0; end < s.length(); ++end)
        {
            // dupe found, move start up
            if (seen[s[end]] >= start)
            {
                start = seen[s[end]] + 1;
            }
            seen[s[end]] = end;

            result = max(result, end - start + 1);



        }

        return result;


    }


};


int main()
{



    Solution s;
    cout << s.lengthOfLongestSubstring("dvdf");
}

