#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution 
{
public:
    int nextBeautifulNumber(int n) 
    {

        for (int i = n + 1;; ++i)
        {
            // get freq count
            int numCount[10] = { 0 };
            for (int j = i; j > 0; j /= 10)
            {
                numCount[j % 10]++;
            }
            bool isBalanced = true;
            for (int k = 0; k < 10; ++k)
            {

                // if not balanced its automatically a fail
                if (numCount[k] && numCount[k] != k)
                {
                    isBalanced = false;
                    break;
                }
            }
            if (isBalanced)
            {
                return i;
            }


        }

        return -1;


    }

};

int main()
{
    Solution s;
    s.nextBeautifulNumber(1);
    return 0;
}