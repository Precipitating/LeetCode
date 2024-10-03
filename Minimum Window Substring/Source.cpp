#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> charPos;
        for (char c : t)
        {
            ++charPos[c];
        }

        int tCount = t.size();
        int left = 0, right = 0;
        int minLen = INT_MAX;
        int minStart = 0;

        while (right < s.size())
        {
            // Expand the window by including s[right]
            if (charPos[s[right]] > 0)
            {
                --tCount;
            }
            --charPos[s[right]];  // Decrease the count of the current character in the window
            ++right;

            // If we have all characters from t in the current window
            while (tCount == 0)
            {
                // Update the minimum window size if this window is smaller
                if ((right - left) < minLen)
                {
                    minStart = left;
                    minLen = right - left;
                }

                // Shrink the window from the left
                ++charPos[s[left]];  // Restore the count of the character we're excluding from the window

                // If s[left] was a required character and its count is now insufficient, we need to increase tCount
                if (charPos[s[left]] > 0)
                {
                    ++tCount;
                }

                ++left;
            }
        }

        return (minLen != INT_MAX) ? s.substr(minStart, minLen) : "";
    }
};

int main()
{
    Solution s;
    cout << s.minWindow("ADOBECODEBANC", "ABC");
    return 0;
}