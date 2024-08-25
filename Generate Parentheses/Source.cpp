#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;

        GenerateCombo("", result, n, 0, 0);

        return result;

    }

    void GenerateCombo(string curr, vector<string>& result, int n, int openCount, int closeCount)
    {
        if (curr.size() == (n * 2))
        {
            result.push_back(curr);
            return;
        }
        
        if (openCount < n)
        {
            GenerateCombo(curr.append("("), result, n, openCount + 1, closeCount);
            curr.pop_back();
        }

        // we don't want another ) if it doesn't pair up with an available ( 
        if (closeCount < n && (closeCount + 1) <= openCount)
        {
            GenerateCombo(curr.append(")"), result, n, openCount, closeCount+1);
            curr.pop_back();
        }

    }
};

int main()
{
    Solution s;
    int num = 3;
    s.generateParenthesis(num);
    return 0;
}