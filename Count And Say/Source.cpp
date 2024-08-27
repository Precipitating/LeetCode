#include <iostream>
#include <string>
using namespace std;

class Solution 
{
public:
    string countAndSay(int n)
    {
        if (n == 1) { return "1"; }
        if (n == 2) { return "11"; }
        string result = "11";

        return Encode(n - 2, result);
    }

    string Encode(int n, string str)
    {
        if (n <= 0) { return str; }

        string newStr;
        int count = 0;
        char currentChar;
        for (size_t i = 0; i < str.length(); ++i)
        {
            currentChar = str[i];
            if (str[i] != str[i+1])
            {
                ++count;
                newStr.push_back(count + '0');
                newStr.push_back(str[i]);
                count = 0;

            }
            else
            {
                ++count;

            }

        }

        return Encode(n - 1, newStr);

    }
};


int main()
{
    Solution s;
    int num = 14;
    cout << s.countAndSay(num);
}