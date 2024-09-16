#include <iostream>
#include <vector>
using namespace std;


class Solution 
{
public:
    int countPrimes(int n) 
    {
        if (n < 2) { return 0; }
        int answer = 0;
        int prime = 2;
        vector<bool> marked(n);

        while (prime < sqrt(n))
        {
            if (!marked[prime])
            {
                for (size_t i = prime * prime; i < n; i+= prime)
                {
                    marked[i] = true;
                }

            }

            ++prime;
        }


        return count(marked.begin() + 2, marked.end(), false);
    }
};



int main()
{
    Solution s;
    cout << s.countPrimes(1000000);
    return 0;
}