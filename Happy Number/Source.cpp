#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    //// o(log n^2) approach
    //bool isHappy(int n)
    //{
    //    bool result = false;
    //    int currentSum = -1;
    //    int currentNum = n;
    //    unordered_set<int> seenValues;
    //    while (currentSum != 1)
    //    {
    //        currentSum = 0;
    //        while (currentNum != 0)
    //        {
    //            currentSum += pow(currentNum % 10, 2);
    //            currentNum /= 10;
    //        }
    //        // check if sum already exists, as it means its a cycle
    //        if (seenValues.count(currentSum) == 0)
    //        {
    //            seenValues.insert(currentSum);
    //        }
    //        else
    //        {
    //            break;
    //        }
    //        currentNum = currentSum;
    //    }
    //    if (currentSum == 1)
    //    {
    //        result = true;
    //    }
    //    return result;
    //}

    // o(Log n) approach with o(1) space complexity. hare and tortoise
    bool isHappy(int n)
    {
        bool result = false;

        int tortoise = getSum(n);
        int hare = getSum(getSum(n));

        while (tortoise != hare && hare != 1)
        {
            tortoise = getSum(tortoise);
            hare = getSum(getSum(hare));
        }

        if (hare == 1)
        {
            result = true;
        }


        return result;
    }

    int getSum(int n)
    {
        int sum = 0;
        
        while (n != 0)
        {
            int currentDig = n % 10;
            sum += currentDig * currentDig;
            n /= 10;

        }

        return sum;
    }
};


int main()
{
    Solution s;
    cout << s.isHappy(2);
    return 0;
}