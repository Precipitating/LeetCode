#include <iostream>


class Solution
{
public:
    // binary search O(log n)
    int mySqrt(int x)
    {
        if (x == 0 || x == 1) { return x; }

        int start = 0, end = x;

        while (start <= end)
        {
            int midPoint = start + (end - start) / 2;
            long long squareOfMid = (long long)midPoint * midPoint;
            // move search space left if square of mid is > x 
            if (squareOfMid > x)
            {
                end = midPoint - 1;
            }
            // move search space right if mid > x
            else if (squareOfMid < x)
            {
                start = midPoint + 1;
            }
            else
            {
                return midPoint;
            }
        }

        return end;

    }
};



int main()
{
    Solution s;

    std::cout << s.mySqrt(2147395599);

    return 0;
}