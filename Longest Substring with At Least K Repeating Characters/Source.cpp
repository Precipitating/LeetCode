#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int longestSubstring(string s, int k) 
    {
        int result = 0;

        for (int i = 1; i <= 26; ++i)
        {
            unordered_map<char, int> countMap;
            int left = 0; int right = 0;
            int uniqueChars = 0;
            int biggerThanK = 0;

            while (right < s.size())
            {
                // if doesnt exist in map, its a new char 
                if (countMap[s[right]] == 0) { ++uniqueChars; }
                // increment char counter
                ++countMap[s[right]];
                // if char count > k then increase right window
                if (countMap[s[right]] == k) { ++biggerThanK; }
                ++right;

                // if unique count is bigger than target, shrink window from left
                while (uniqueChars > i)
                {
                    if (countMap[s[left]] == k) { --biggerThanK; }
                    --countMap[s[left]];
                    if (countMap[s[left]] == 0) { --uniqueChars; }
                    
                    ++left;
                }
                // update current result`
                if (uniqueChars == biggerThanK) { result = max(result, right - left); }
            }
        }

        return result;

    }
};



int main()
{
    Solution s;
    cout << s.longestSubstring("aaabb", 3);
    return 0;
}