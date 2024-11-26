#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    bool splitString(string s) 
    {
        if (s.size() <= 1) { return false; }
        return Solve(0, 0, -1, s);
    }

    bool Solve(int idx,int count, long long prev, string& s)
    {
        // if its > 1 then we got 2 descending numbers
        if (idx == s.size()) { return count > 1; }

        unsigned long long num = 0;
        for (size_t i = idx; i < s.size(); i++)
        {
            num = num * 10l + s[i] - '0';
            string sub = s.substr(idx, i);

            if (prev - num == 1 || prev == -1)
            {
                if (Solve(i + 1, count + 1, num, s))
                {
                    return true;
                }
            }
            if (num > prev && prev != -1) { break; }


        }

        return false;

    }
};

int main()
{
    Solution s;
    cout << s.splitString("1234");
    return 0;
}