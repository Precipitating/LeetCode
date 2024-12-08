#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool IsPalindrome(const string& s)
    {
        bool result = true;
        int first = 0; int last = s.size() - 1;
        while (first < last)
        {
            if (s[first] != s[last]) { result = false; break; }
            ++first;
            --last;
        }

        return result;
    }


    int maxProduct(string s) 
    {
        string first;
        string second;
        Solve(0, first, second, s);
        return result;
    }

    void Solve(int idx, string& first, string& second, const string& s)
    {
        if (idx >= s.size())
        {
            if (IsPalindrome(first) && IsPalindrome(second))
            {
                result = max(result, (int)first.size() * (int)second.size());
            }
            return;
        }

        first.push_back(s[idx]);
        Solve(idx + 1, first, second, s);
        first.pop_back();

        second.push_back(s[idx]);
        Solve(idx + 1, first, second, s);
        second.pop_back();

        Solve(idx + 1, first, second, s);

    }

private:
    int result = false;
};

int main()
{
    Solution s;
    s.maxProduct("leetcodecom");
    return 0;
}
