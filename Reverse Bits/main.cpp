#include <iostream>

using namespace std;
class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t reversed = 0;

        for (size_t i = 0; i < 32; ++i)
        {
            // shift reversed left so we can apply the next bit
            reversed <<= 1;
            // get last bit from right
            uint32_t bit = n & 1;
            // add the bit to reversed variable
            reversed |= bit;
            // shift n right, so we can process the next bit (right to left)
            n >>= 1;

        }
        return reversed;
    }
};


int main()
{
    Solution s;
    uint32_t bits = uint32_t("00000010100101000001111010011100");
    cout << s.reverseBits(bits);
    return 0;
}