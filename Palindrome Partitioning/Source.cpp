#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution 
{
public:
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> result;
        vector<string> curr;
        Solve(s,0,curr, result);

        return result;
    }


    void Solve(const string& str, int idx, vector<string>& current, vector<vector<string>>& result)
    {
        if (idx == str.size())
        {
            result.push_back(current);
            return;
        }
        

        for (size_t i = idx; i < str.size(); ++i)
        {
            if (isPalindrome(str, idx, i))
            {
                current.push_back(str.substr(idx, i-idx+1));
                Solve(str, i + 1, current, result);
                current.pop_back();

            }

        }
    }

    bool isPalindrome(const string& str, int first, int last)
    {

        while (first < last)
        {
            if (str[first] == str[last])
            {
                ++first;
                --last;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution s;
    string str = "aab";

    s.partition(str);

    return 0;
}