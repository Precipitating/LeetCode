#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> storedTokens;

        for (const string& token : tokens)
        {
            if (token == "+" || token == "-" || token == "/" || token == "*")
            {
                int second = storedTokens.top(); storedTokens.pop();
                int first = storedTokens.top(); storedTokens.pop();

                switch (token[0])
                {
                case '+': storedTokens.push(first + second); break;
                case '/': storedTokens.push(first / second); break;
                case '*': storedTokens.push(first * second); break;
                case '-': storedTokens.push(first - second); break;
                }
                
            }
            else
            {
                storedTokens.push(stoi(token));
            }
        }

        return storedTokens.top();

    }
};


int main()
{
    Solution s;
    vector<string> tokens = { "10","6","9","3","+","-11","*","/","*","17","+","5","+" };
    cout << s.evalRPN(tokens);
    return 0;
}