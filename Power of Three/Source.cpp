#include <iostream>
#include <type_traits>
using namespace std;

class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        // attempted using log, but floating point precision issues.
        // solution is to get highest power of 3 (int can hold)
        // which should perfectly divide if it its a power of 3
        // O(1)

        if (n <= 0)
        {
            return false;

        }
        int highest = 1162261467;

        return (highest % n) == 0;


        



    }
};

int main()
{
    Solution s;
    cout << s.isPowerOfThree(4782967);



    return 0;
}