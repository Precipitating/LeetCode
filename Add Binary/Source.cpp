#include <iostream>
#include <string>
using namespace std;


class Solution
{
public:
    string addBinary(string a, string b)
    {
        int remainders = 0;
        string answer;

        // pad the strings so they're same value.
        if (a.length() < b.length())
        {
            int diff = b.length() - a.length();
            a.insert(0, diff, '0');
        }
        else if (b.length() < a.length())
        {
            int diff = a.length() - b.length();
            b.insert(0, diff, '0');
        }
        // reverse so cleaner calculations.
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        for (size_t i = 0; i < a.length(); ++i)
        {
            if (a[i] == '1' && b[i] == '1')
            {
                if (remainders > 0)
                {
                    answer.append("1");
                }
                else
                {
                    answer.append("0");
                    ++remainders;
                }
            }
            else if ((a[i] == '1' || b[i] == '1') && remainders > 0)
            {
                answer.append("0");

            }
            else if(a[i] == '0' && b[i] == '0')
            {
                if (remainders > 0)
                {
                    --remainders;
                    answer.append("1");
                }
                else
                {
                    answer.append("0");
                }

            }
            else
            {
                answer.append("1");
            }

        }

        if (remainders > 0)
        {
            answer.append("1");
        }
        reverse(answer.begin(), answer.end());

        return answer;

    }
};



int main()
{
    Solution s;
    s.addBinary("1", "111");
}