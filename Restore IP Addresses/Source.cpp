#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> restoreIpAddresses(string s) 
    {
        vector<string> result;
        if ( s.size() < 4 || s.size() > 12) { return result; }
        BackTrack(0, 0,"", s, result);
        return result;
    }

    bool IsValid(const string& s)
    {
        // max len is 256, so 3 characters
        if (s.empty() || s.size() > 3 ) { return false; }
        // no leading zeroes 
        if (s.size() > 1 && s[0] == '0') { return false; }
        // ensure its within 0 -> 255
        return stoi(s) <= 255;
    }

    void BackTrack(int idx, int dotCount, string curr, const string& s, vector<string>& result)
    {
        if (dotCount == 3)
        {
            if (IsValid(s.substr(idx)))
            {
                result.push_back(curr + s.substr(idx));
            }

            return;
        }

        for (int i = idx; i < s.size(); ++i)
        {
            string p = s.substr(idx, i - idx + 1);
            if (IsValid(p))
            {
                BackTrack(i + 1, dotCount + 1, curr + p + '.', s, result);
            }
        }


    }
};

int main()
{
    Solution s;
    string str = "25525511135";
    s.restoreIpAddresses(str);
}