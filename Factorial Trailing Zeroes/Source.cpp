#include <iostream>
using namespace std;

class Solution
{
public:
    int trailingZeroes(int n)
    {
        int result = 0;
        while (n != 0)
        {
            n /= 5;
            result += n;
        }

        return result;
    }

};



int main()
{
    Solution s;
    cout << s.trailingZeroes(23);

    return 0;
}