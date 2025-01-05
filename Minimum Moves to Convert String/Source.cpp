#include <iostream>
using namespace std;

class Solution
{
public:
    int minimumMoves(string s) 
    {
        int result = 0;
        for (size_t i = 0; i < s.size(); ++i)
        {
            if (s[i] == 'X')
            {
                ++result;
                i += 2;
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    s.minimumMoves("XXOX");

    return 0;
}