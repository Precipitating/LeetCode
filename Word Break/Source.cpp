#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        int strLength = s.size();
        vector<bool> dp(s.size() + 1, false);

        dp[s.size()] = true;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            for (const string& word : wordDict)
            {
                // if substring does not go out of bounds, and is equal to a word
                // from wordDict, set position to true in DP
                string subStr = s.substr(i, word.size());
                if (i + word.size() <= s.size() && subStr == word)
                {
                    dp[i] = dp[i + word.size()];
                }

                if (dp[i])
                {
                    break;
                }
            }




        }

        return dp[0];

    }
};

int main()
{
    Solution s;
    string str = "aaaaaaa";
    vector<string> wordDict = { "aaaa","aaa"};
    s.wordBreak(str, wordDict);
    return 0;

}