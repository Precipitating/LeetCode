#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution 
{
public:
    vector<string> removeInvalidParentheses(string s)
    {
        vector<string> result;
        unordered_set<string> visited;
        queue<string> q;
        bool found = false;

        q.push(s);
        visited.insert(s);

        while (!q.empty())
        {
            string curr = q.front(); q.pop();

            if (IsValid(curr))
            {
                result.push_back(curr);
                found = true;
            }
            if (found) { continue; }

            for (size_t i = 0; i < curr.size(); ++i)
            {
                if (curr[i] == '(' || curr[i] == ')')
                {
                    string nextStr = curr;
                    nextStr.erase(i, 1);

                    if (!visited.count(nextStr))
                    {
                        visited.insert(nextStr);
                        q.push(nextStr);

                    }

                }
            }


        }

        return result;
    }

    bool IsValid(const string& s)
    {
        int cntr = 0;

        for (char c : s)
        {
            if (c == '(') { ++cntr; }
            else if (c == ')') { --cntr; }

            if (cntr < 0) { break; }
        }

        return cntr == 0;
    }
};

int main()
{
    Solution s;
    string str = ")(";
    s.removeInvalidParentheses(str);
    return 0;
}