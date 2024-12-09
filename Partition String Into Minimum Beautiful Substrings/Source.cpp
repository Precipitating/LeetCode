#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int minimumBeautifulSubstrings(string s) 
    {
        vector<int> dp(s.size() + 1, s.size() + 1);

        dp[0] = 0;

        // start position of substr
        for (int i = 0; i < s.size(); ++i)
        {
            // no leading zeroes
            if (s[i] == '0') { continue; }

            // curr = binary val of substr
            for (int j = i, curr = 0; j < s.size(); j++)
            {
                curr = curr * 2 + s[j] - '0';

                // if power of 5 its a valid substr
                // 15625 is largest power of 5 in 32 bit int range
                if (15625 % curr == 0)
                {
                    dp[j + 1] = min(dp[j + 1], dp[i] + 1);
                }
            }
        }

        return dp[s.size()] > s.size() ? -1 : dp[s.size()];
    }
};

int main()
{
    Solution s;
    s.minimumBeautifulSubstrings("1011");

    return 0;
}

