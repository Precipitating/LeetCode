#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<long long> maximumEvenSplit(long long finalSum)
    {
        vector<long long> result;
        if (finalSum % 2 != 0) { return result; }
        long long curr = 2;

        while (finalSum > 0)
        {
            if (curr <= finalSum)
            {
                result.push_back(curr);
                finalSum -= curr;
            }
            else
            {
                result.back() += finalSum;
                break;
            }
            curr += 2;
        }

        return result;
    }

};

int main()
{
    Solution s;
    long long num = 28;
    s.maximumEvenSplit(num);
    return 0;
}