#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string removeDuplicateLetters(string s) 
    {
        vector<int> freq(26, 0), visited(26, 0);

        // add char count to freq
        for (char c : s)
        {
            ++freq[c - 'a'];
        }

        for (int i = 0; i < s.size(); ++i)
        {
            --freq[s[i] - 'a'];

            if (visited[s[i] - 'a']) { continue; }

            // if last result char is lexiographically higher than current, remove it
            // ensure the letter is choosable, checking via freq vector.
            while (!result.empty() && result.back() > s[i] && freq[result.back() - 'a'] > 0)
            {
                visited[result.back() - 'a'] = 0;
                result.pop_back();
            }

            result.push_back(s[i]);

            visited[s[i] - 'a'] = 1;

        }


        return result;
    }
private:
    string result;
};

int main()
{
    Solution s;
    s.removeDuplicateLetters("bcabc");
    return 0;
}