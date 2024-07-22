#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath> 
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> romanMap = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
        int answer = 0;

        for (size_t i = 0; i < s.size(); ++i)
        {
            char currentNumeral = s[i];
            // if we arrive at last symbol, dont bother checking ahead and finish up.
            if (i == s.size() - 1)
            {
                answer += romanMap[currentNumeral];
                break;
            }

            // if next char is bigger, subtract both values and ignore next char.
            if (romanMap[s[i + 1]] > romanMap[currentNumeral] )
            {
                answer += romanMap[s[i + 1]] - romanMap[currentNumeral]; 
                ++i;
            }
            else
            {
                answer += romanMap[currentNumeral];
            }

            
        }

        return answer;

    }



};

int main()
{
    Solution sol;
    string romanNumeral = "IV";
    cout << sol.romanToInt(romanNumeral);

    return 0;
}

