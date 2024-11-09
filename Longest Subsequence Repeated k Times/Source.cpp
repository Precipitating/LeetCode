#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;


class Solution 
{
public:
    string longestSubsequenceRepeatedK(string s, int k) 
    {
        vector<int> freqCount(26,0);
        vector<char> possibleChars;
        
        // tally up character count in s
        for (char c : s)
        {
            ++freqCount[c - 'a'];
        }

        // store characters that >= k in freqCount
        for (char i = 'a'; i <= 'z'; ++i)
        {
            if (freqCount[i - 'a'] >= k)
            {
                possibleChars.push_back(i);
            }
        }

        // BFS
        string result = "";
        queue<string> q;
        q.push("");

        while (!q.empty())
        {
            string curr = q.front(); q.pop();

            if (curr.length() * k > s.length())
            {
                return result;
            }

            for (char c : possibleChars)
            {
                string newSub = curr + c;
                if (isSubSeq(k, newSub, s))
                {
                    q.push(newSub);
                    result = newSub;
                }
            }


        }


        return result;


    }

    // check if subseq appears more than k times
    bool isSubSeq(int k, const string& subseq, const string& s)
    {
        int i = 0;

        for (char c : s)
        {    
            if (c == subseq[i])
            {
                ++i;
                if (i == subseq.length())
                {
                    --k;
                    if (k == 0) { return true; }
                    i = 0;
                }
            }
        }

        return false;

    }
};

int main()
{
    Solution s;
    string str = "arzwpdlarzwpl";
    int k = 2;
    s.longestSubsequenceRepeatedK(str, k);

    return 0;
}