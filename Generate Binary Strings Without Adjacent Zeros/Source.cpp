#include <iostream>
#include <vector>
#include <string>
#include <bitset>
using namespace std;

class Solution 
{
public:
    vector<string> validStrings(int n)
    {
        if (n == 1) { return vector<string>{ "0", "1" }; }

        vector<string> result;
        string curr;

        Solve(curr, n, result);


        return result;
    }

    void Solve(string& curr, int n, vector<string>& result)
    {
        if (curr.length() == n)
        {
            if (curr.find('1') != string::npos)
            {
                result.push_back(curr);
            }
            return;
        }

        curr.push_back('1');
        Solve(curr, n, result);
        curr.pop_back();

        if (curr.empty() || curr.back() != '0' )
        {
            curr.push_back('0');
            Solve(curr, n, result);
            curr.pop_back();
        }



    }
};


int main()
{
    Solution s;
    s.validStrings(3);

    return 0;
}