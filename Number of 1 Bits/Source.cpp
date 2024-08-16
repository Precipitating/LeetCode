#include <iostream>
using namespace std;
class Solution
{
public:
    // O(1) time complexity
    int hammingWeight(int n)
    {
        int result = 0;

        for (size_t i = 0; i < sizeof(n) * CHAR_BIT; ++i)
        {
            int bit = (n >> i) & 1;
            if (bit == 1)
            {
                ++result;
                
            }
        }

        return result;
    }
};


int main()
{
    Solution s;

    cout << s.hammingWeight(2147483645);
    return 0;

}