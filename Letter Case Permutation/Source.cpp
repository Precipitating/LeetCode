#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> letterCasePermutation(string s) 
    {
        vector<string> result;
        BackTrack(0, s, result);

        return result;

    }
    
    void BackTrack(int idx, string& s, vector<string>& result)
    {
        if (idx >= s.size())
        { 
            result.push_back(s);
            return;
        }

       // char opposite = (islower(s[idx]) ? toupper(s[idx]) : tolower(s[idx]));
       // or use a bit trick to go from lower/uppercase to its opposite
        char opposite = s[idx] ^ (1 << 5);

        if (isalpha(s[idx]))
        {
            s[idx] = opposite;
            BackTrack(idx + 1, s, result);
            s[idx] ^= (1 << 5);
        }

        BackTrack(idx + 1,s, result);



    }
};

int main()
{
    Solution s;
    s.letterCasePermutation("a1b2");
    return 0;
}