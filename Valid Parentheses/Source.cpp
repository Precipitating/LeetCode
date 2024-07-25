#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<int> stack;

        // count brackets
        pair<int, int> countSquareBrackets = make_pair(
            count(s.begin(), s.end(), '['), count(s.begin(), s.end(), ']'));
        pair<int, int> countBrackets = make_pair(
            count(s.begin(), s.end(), '('), count(s.begin(), s.end(), ')'));
        pair<int, int> countCurlyBrackets = make_pair(
            count(s.begin(), s.end(), '{'), count(s.begin(), s.end(), '}'));

        // check if pairs match, if not its false.
        if (countSquareBrackets.first != countSquareBrackets.second ||
            countBrackets.first != countBrackets.second ||
            countCurlyBrackets.first != countCurlyBrackets.second)
            return false;

        // check if correct closing order
        for (const char& bracket : s)
        {
            if (bracket == '(' || bracket == '{' || bracket == '[')
            {
                stack.push(bracket);
            }
            else
            {
                // if its empty, then the closing bracket and open bracket must be in wrong order
                if (stack.size() == 0)
                    return false;

                switch (stack.top())
                {
                case '(':
                {
                    if (bracket == ')')
                    {
                        stack.pop(); 
                    }
                    else
                    { 
                        return false;
                    }
                    break;
                }

                case '{':
                    if (bracket == '}')
                    {
                        stack.pop();
                    }
                    else
                    {
                        return false;
                    }
                    break;
                case '[':
                    if (bracket == ']')
                    {
                        stack.pop();
                    }
                    else
                    {
                        return false;
                    }
                    break;
                }

            }
        }

        return true;
    }

};

int main()
{
    string characters = "(){}}{";

    Solution s;
    bool result = s.isValid(characters);

    cout << result;
}