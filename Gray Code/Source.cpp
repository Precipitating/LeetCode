#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

class Solution
{
public:
    vector<int> grayCode(int n) 
    {
        vector<int> result;
        bitset<32> bits;

        Solve(n, bits, result);
        return result;

    }


    void Solve(int n, bitset<32>& bits, vector<int>& result)
    {
        if (n == 0) { result.push_back(bits.to_ulong()); }
        else
        {
            Solve(n - 1, bits, result);
            bits.flip(n-1);
            Solve(n - 1, bits, result);

        }

    }
};
int main()
{
    Solution s;
    s.grayCode(2);
    return 0;
}