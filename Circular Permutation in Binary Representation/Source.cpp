#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    vector<int> circularPermutation(int n, int start)
    {
        vector<int> result;
        
        // 1 << n = total numbers in n bit gray code sequence
        for (size_t i = 0; i < (1 << n); ++i)
        {
            // the formula i ^ i >> 1 gets the gray code
            // but we need to start from 'start' so we 
            // xor with start, whilst getting the gray code.
            result.push_back(start ^ i ^ (i >> 1));
        }

        return result;
    }

};

int main()
{
    Solution s;

    s.circularPermutation(2, 3);
    return 0;
}
