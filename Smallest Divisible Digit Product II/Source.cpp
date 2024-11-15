#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:

    long long GCD(long long a, long long b)
    {
        if (a == 0) { return b; }

        return GCD(b % a, a);
    }
    // true if 'a' is larger than b
    // if same length, check if a is lexicographically bigger.
    bool CompareLength(const string& a, const string& b)
    {
        return (a.length() > b.length()) ? true : (a.length() < b.length()) ? false : a.compare(b) > 0;

    }
    string smallestNumber(string num, long long t)
    {
        n = num.length();
        // track divisibility for each digit
        vector<long> remind(n + 1);
        remind[0] = t;
        int end = n;

        // calculate divisibility for each position
        for (int i = 0; i < n; ++i)
        {
            // we dont want 0's 
            if (num[i] == '0') { end = i + 1; break; }
            remind[i + 1] = remind[i] / GCD(remind[i], num[i] - '0');

        }

        // if divisible by t, we got the result
        if (remind[n] == 1 && end == n) { return num; }

        // if not divisible, increment digits from right -> left
        for (int i = end - 1; i >= 0; --i)
        {
            while (num[i] < '9')
            {
                long tt = remind[i];
                num[i]++;
                tt /= GCD(tt, num[i] - '0'); // update divisiblity

                // Directly update the remaining digits if possible
                for (int j = n - 1; j > i; --j)
                {
                    for (int k = 9; k > 0; --k)
                    {
                        if (tt % k == 0) {
                            tt /= k;
                            num[j] = '0' + k;
                            break;
                        }
                    }
                }
                if (tt == 1) { return num; }

            }
        }

        // if still no result via digit incrementing, start factorizing t to digits
        string res;

        for (size_t i = 9; t > 1 && i > 1; --i)
        {
            while (t % i == 0) // factor digits from 9 -> 2
            {
                res += to_string(i);
                t /= i;
            }
        }

        // still not solved, its impossible then
        if (t != 1) { return "-1"; }
        // reverse to get smallest number
        reverse(res.begin(), res.end());
        if (CompareLength(res, num)) { return res; }
        if (res.length() == num.length()) { return "1" + res; }

        int dif = num.length() - res.length();
        if (CompareLength(string(dif, '1') + res, num)) { return string(dif, '1') + res; }
        return string(dif + 1, '1') + res;




    }
private:
    int n;
};




int main()
{
    Solution s;
    cout << s.smallestNumber("78", 42);
    return 0;
}