#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;



class Solution
{
public:
    vector<string> braceExpansionII(string expression) 
    {
        set<string> resultSet = BackTrack(expression, 0);

        return vector<string>(resultSet.begin(), resultSet.end());

    }

    set<string> BackTrack(const string& str, int start)
    {
        set<string> curr, temp;
        vector<string> currVec = { "" };

        while (start < str.size())
        {
            if (str[start] == '}')
            {
                ++start;
                break;
            }
            switch (str[start])
            {
            case '{':
            {
                int end = FindClosingBrace(str, start);
                temp = BackTrack(str, start + 1);

                vector<string> next;
                for (const string& pre: currVec)
                {
                    for (const string& suff : temp)
                    {
                        next.push_back(pre + suff);
                    }
                }
                currVec = move(next);
                start = end + 1;
                break;
            }
            case ',':
            {
                curr.insert(currVec.begin(), currVec.end());
                currVec.clear();
                currVec.push_back("");
                ++start;
                break;

            }
                
            default:
            {
                for (string& s : currVec)
                {
                    s += str[start];
                }
                ++start;
                break;
            }
            }
        }

        curr.insert(currVec.begin(), currVec.end());
        return curr;
    }

    int FindClosingBrace(const string& str, int start)
    {
        int bal = 0;
        for (int i = start; i < str.size(); ++i)
        {
            if (str[i] == '{') { bal++; }
            if (str[i] == '}') { bal--; }
            if (bal == 0) { return i; }
        }
        return -1;
    }
};


int main()
{
    Solution s;
    string expression = "{a,b}{c,{d,e}}";
    s.braceExpansionII(expression);
    return 0;
}