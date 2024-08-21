#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> answer;
        answer.reserve(n);

        string fizzBuzz = "FizzBuzz";
        string fizz = fizzBuzz.substr(0, 4);
        string buzz = fizzBuzz.substr(4, fizzBuzz.size());

        for (size_t i = 1; i < (n + 1); ++i)
        {
            if (((i % 3) == 0) && ((i % 5) == 0))
            {
                answer.push_back(fizzBuzz);
            }
            else if ((i % 3) == 0)
            {
                answer.push_back(fizz);
            }
            else if ((i % 5) == 0)
            {
                answer.push_back(buzz);
            }
            else
            {
                answer.push_back(to_string(i));
            }
        }


        return answer;
    }
};

int main()
{
    Solution s;
    s.fizzBuzz(15);

    return 0;

}