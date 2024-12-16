#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int strongPasswordChecker(string password) 
    {
        // conditions: 6 - 20 chars
        // 1 lowercase, 1 uppercase, 1 digit
        // no three repeating characters in a row
        int result = 0;
        bool isUpper = false;
        bool isDigit = false;
        bool isLower = false;
        int missingTypes = 3;
        int n = password.size();

        // do some preliminary checks

        for (char c : password) 
        {
            if (islower(c)) isLower = true;
            if (isupper(c)) isUpper = true;
            if (isdigit(c)) isDigit = true;
        }

        if (isLower) {--missingTypes; }
        if (isUpper) {--missingTypes; }
        if (isDigit) {--missingTypes; }


        int changes = 0, oneRepeat = 0, twoRepeat = 0;
        
        // find triple repeats
        for (int i = 2; i < n; ++i)
        {
            // if triple consequetive characters found...
            if (password[i] == password[i - 1] && password[i - 1] == password[i - 2])
            {
                // find out how long this repetition is
                int len = 2;
                while (i < n && password[i] == password[i - 1])
                {
                    ++len;
                    ++i;
                }
                // calculate changes needed to fix the repetition
                // one change can resolve 3 repeats (aaa -> aXa)
                changes += len / 3;

                // track remainders
                if (len % 3 == 0) { ++oneRepeat; }
                if (len % 3 == 1) { ++twoRepeat; }
                --i;
            }
        }

        // determine changes required

        if (n < 6)
        {
            result = max(missingTypes, 6 - n);
        }
        else if (n <= 20)
        {
            result = max(missingTypes, changes);
        }
        else
        {
            int deletions = n - 20;
            changes -= min(deletions, oneRepeat * 1) / 1;
            changes -= min(max(deletions - oneRepeat, 0), twoRepeat * 2) / 2;
            changes -= min(max(deletions - oneRepeat - 2 * twoRepeat, 0), changes * 3) / 3;
            result = deletions + max(missingTypes, changes);
        }


        return result;
    }
};

int main()
{
    Solution s;
    s.strongPasswordChecker("ABABABABABABABABABAB1");
    return 0;
}