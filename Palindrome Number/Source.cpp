#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    // solution 1
    //bool isPalindrome(int x)
    //{
    //    string toStr = to_string(x);
    //    string reversed = { toStr.rbegin(), toStr.rend() };

    //    return (toStr == reversed);
    //}

    // solution 2, no string conversion
    bool isPalindrome(int x)
    {
        // it's not a palindrome if its less than 0
        if (x < 0)
        {
            return false;
        }

        long long reversed = 0;
        long long tempX = x;
        while (tempX != 0)
        {
            // extract last digit
            long long lastDig = tempX % 10;
            //multiply by 10 to add 0 to the end, then add the last digit to emulate concatenation
            reversed = (reversed * 10) + lastDig;
            // remove last digit
            tempX /= 10;
        }

        return x == reversed;

    }
};


int main()
{
    Solution s;
    int num = 121;
    cout << s.isPalindrome(num);

    return 0;
}
