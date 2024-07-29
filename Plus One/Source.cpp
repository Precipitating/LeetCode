#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int>& digits)
    {
        if (digits[digits.size() - 1] < 9)
        {

           digits[digits.size() - 1] += 1;
           return digits;

        }

        digits.reserve(1);


        for (int i = digits.size() - 1; i > -1; --i)
        {

            if (i == 0 && digits[i] == 9)
            {
                digits[i] = 1;
                digits.push_back(0);
            }
            else if (digits[i] == 9)
            {
                digits[i] = 0;

            }
            else
            {
                digits[i] += 1;
                break;
            }
        }


        return digits;
    }



};


int main()
{
    Solution s;
    vector<int> num = { 9,8,9,9 };
    s.plusOne(num);

    return 0;
}