#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
    int calculate(string s) 
    {
        s = '+' + s + '+';
        int result = 0;
        stack<int> results;

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '+' || s[i] == '-')
            {
                (s[i] == '+') ? results.push(toNum(i,s)) : results.push(-toNum(i,s));
            }
            else if (s[i] == '*')
            {
                int prevNum = results.top();  results.pop();
                int currNum = toNum(i, s) * prevNum;

                results.push(currNum);


            }
            else if (s[i] == '/')
            {
                int prevNum = results.top();  results.pop();
                int currNum = prevNum / toNum(i, s);

                results.push(currNum);
            }

        }
        
        while (!results.empty())
        {
            result += results.top(); results.pop();
        }


        return result;
    }

    int toNum(int& pos, const string& str)
    {
        ++pos;

        if (pos == str.size()) { return 0; }

        int result = 0;
        while (isspace(str[pos])) { ++pos; }

        while (isdigit(str[pos]))
        {
            result *= 10;
            result += str[pos] - '0';
            ++pos;
        }
        --pos;
        return result;
    }


};

int main()
{
    Solution s;
    cout << s.calculate("3+5 / 2 ");
    return 0;
}