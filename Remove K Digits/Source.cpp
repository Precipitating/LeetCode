#include <iostream>
#include <string>
using namespace std;

class Solution 
{
public:
    string removeKdigits(string num, int k) 
    {
        // use string type as stack, no need to include a stack
        for (char c : num)
        {
            // pop back of result if current num < back of result.
            // only if we still have digits to delete (k)
            while (!result.empty() && c < result.back() && k > 0)
            {
                result.pop_back();
                --k;
            }

            // (if result size is 0 and char is 0, then adding makes it = 0)
            // (this is used to check for leading zeroes, which we don't want)
            if (result.size() + (c - '0') != 0)
            {
                result += c;
            }
        }

        // if the number is already in ascending order the entire way,
        // then just pop 3 digits from the back and it'll be the smallest.
        while (k-- && !result.empty())
        {
            result.pop_back();
        }


        return (!result.empty()) ? result : "0";
    }

private:
    string result;
};

int main()
{
    Solution s;
    s.removeKdigits("1234567", 3);
    return 0;
}