#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    bool judgePoint24(vector<int>& cards) 
    {
        bool result = false;
        vector<double> cardD(cards.begin(), cards.end());

        return Solve(cardD);



    }

    bool Solve(vector<double>& nums)
    {
        // reduce until we reach 1 number and check if its 24
        if (nums.size() == 1)
        {
            // since we divide we need to make sure its  close to 24
            return fabs(nums[0] - 24.0) < 1e-6;
        }


        // bruteforce each pair

        for (size_t i = 0; i < nums.size(); ++i)
        {
            
            for (size_t j = i + 1; j < nums.size(); ++j)
            {
                vector<double> next;

                // push remaining numbers except from i and j to array
                for (size_t k = 0; k < nums.size(); ++k )
                {
                    if (k != i && k != j) { next.push_back(nums[k]); }
                }

                for (double result : Check(nums[i], nums[j]))
                {
                    next.push_back(result);
                    if (Solve(next))
                    {
                        return true;
                    }

                    next.pop_back();
                }


            }
        }

        return false;

    }

    // get all possible combination results
    vector<double> Check(double a, double b)
    {
        return { a + b, a - b, b - a, a * b, a / b, b / a };
    }
};

int main()
{
    Solution s;
    vector<int> cards = { 1,2,1,2 };
    s.judgePoint24(cards);


    return 0;
}