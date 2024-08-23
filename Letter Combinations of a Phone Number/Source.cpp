#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty()) { return vector<string>(); }
        unordered_map<char, string> map;
        string alphabet = "abcdefghijklmnopqrstuvwxyz";
        vector<string> result;
        int first = 0;
        int combinationCount = 1;
        // add alphabet to map
        for (size_t i = 2; first < alphabet.size(); i++)
        {
            string letters;
            if (i == 7 || i == 9)
            {
                letters = { alphabet[first], alphabet[first + 1], alphabet[first + 2], alphabet[first + 3]};
                first += 4;
            }
            else
            {
                letters = { alphabet[first], alphabet[first + 1], alphabet[first + 2] };
                first += 3;
                
            }
            
            map[i + '0'] = letters;

            


        }

        GetCombinations(digits, 0, "", result,map);
        
        return result;
    }

    void GetCombinations(const string& digits, int idx, const string& curr, vector<string>& result, const unordered_map<char,string>& map)
    {
        if (curr.length() == digits.size())
        {
            result.push_back(curr);
            return;
        }

        for (const char& c : map.at(digits[idx]))
        {
            GetCombinations(digits, idx + 1, curr + c, result, map);
        }
    }
};

int main()
{
    Solution s;
    s.letterCombinations("234");
}