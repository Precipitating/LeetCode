#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string smallestSubsequence(string s, int k, char letter, int repetition) 
    {
        int letterCount = count(s.begin(), s.end(), letter);
        string result;

        for (int i = 0; i < s.size(); ++i)
        {
            while (!result.empty() && result.back() > s[i] &&
                (s.size() - i) + result.size() > k &&
                (result.back() != letter || letterCount > repetition))
            {
                if (result.back() == letter) {++repetition;}

                result.pop_back();

            }

            if (result.size() < k)
            {
                if (s[i] == letter || k - (int)result.size() > repetition)
                {
                    result += s[i];
                    if (s[i] == letter) { --repetition; }
                }
            }

            if (s[i] == letter)
            {
                --letterCount;
            }



        }

        return result;

    }


};

int main()
{
    Solution s;
    s.smallestSubsequence("leet", 3, 'e', 1);
    return 0;
}