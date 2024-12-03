#include <iostream>
#include <string>
#include <string>
using namespace std;


class Solution 
{
public:

    bool isValid(int num, int target)
    {
        if (target < 0 || num < target)
        {
            return false;
        }
        if (num == target) { return true; }

        return isValid(num / 10, target - (num % 10)) || isValid(num / 100, target - num % 100) ||
               isValid(num / 1000, target - num % 1000);


    }
    int punishmentNumber(int n) 
    {
        int result = 0;
        for (size_t i = 1; i <= n; ++i)
        {
            int square = i * i;
            if (isValid(square, i))
            {
                result += square;
            }


        }

        return result;
    }
};

int main()
{
    Solution s;
    s.punishmentNumber(10);
    return 0;
}