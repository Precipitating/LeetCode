#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string getHappyString(int n, int k)
    {
        string result;
        vector<string> strList;
        Solve(n, "", strList);

        if (strList.size() < k) { return ""; }

        return strList[k - 1];
    }


    void Solve(int n, string curr, vector<string>& strList)
    {
        if (curr.size() == n) { strList.push_back(curr); return; }

        for (char c = 'a'; c <= 'c'; ++c)
        {
            if (curr.size() > 0 && curr.back() == c) { continue; }
            Solve(n, curr + c, strList);
        }



    }
};

int main()
{
    Solution s;
    cout << s.getHappyString(3, 9);
    return 0;
}