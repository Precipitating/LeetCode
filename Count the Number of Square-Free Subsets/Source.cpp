#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    int Encode(int num)
    {
        int result = 0;

        // returns -1 if not square free, else encodes to a binary format
        for (const int prime : mp)
        {
            if ((num % prime) == 0)
            {
                // divide and check again to ensure its square free
                num /= prime;
                
                if (num % prime == 0)
                {
                    return -1;
                }

                // append 1 to binary
                result = (result << 1) | 1;
            }
            else
            {
                // append 0 to binary
                result <<= 1;
            }
        }

        return result;
    }
    int squareFreeSubsets(vector<int>& nums) 
    {
        vector<int> dp(1024, 0);
        dp[0] = 1;

        for (int num : nums)
        {
            int mask = Encode(num);
            // ignore if not square free
            if (mask == -1) { continue; }

            for (int j = 0; j < 1024; ++j)
            {
                if ((mask & j) == 0)
                {
                    dp[mask | j] = (dp[mask | j] + dp[j]) % MODULO;
                }
            }

        }

        for (int c : dp)
        {
            result = (result + c) % MODULO;

        }

        // -1 to ignore empty subset
        return (result == 0) ? MODULO - 1 : result - 1;


    }
private:
    int result = 0;
    const int MODULO = 1e9 + 7;
    // primes numbers <= 30
    vector<int> mp = { 2,3,5,7,11,13,17,19,23,29 };

};

int main()
{
    Solution s;
    vector<int> nums = { 3,4,4,5 };
    s.squareFreeSubsets(nums);
    return 0;
}