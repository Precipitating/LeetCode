#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        int count = 0;
        vector<int> storedIdxVals(s.size(),-1);
        Recursion(0, s, count, storedIdxVals);

        return count;
    }

    void Recursion(int idx, const string& str, int& count, vector<int>& storedVals)
    {
        if (str.size() == 0) { return; }
        if (idx == str.size()) { ++count; return; }
        if (str[idx] == '0')
        {
            return;
        }

        if (storedVals[idx] != -1)
        {
            count += storedVals[idx];
            return;
        }


        int currCount = 0;
        // single digit
        if ((str[idx] - '0') <= 9 && (str[idx] - '0') >= 1)
        {
            // go up one
            Recursion(idx + 1, str, currCount, storedVals);

        }

        // double digit
        if (idx + 1 < str.size())
        {
            int combined = (str[idx] - '0') * 10 + (str[idx + 1] - '0');
            if (combined >= 10 && combined <= 26)
            {
                Recursion(idx + 2, str, currCount, storedVals);
            }
        }

        storedVals[idx] = currCount;

        count += currCount;




    }
};

int main()
{
    Solution s;
    string str = "135181825389192013119";
    s.numDecodings(str);
}