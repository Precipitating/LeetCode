#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int maxLength(vector<string>& arr) 
    {
        int result = 0;
        Solve(0, "", arr, result);
        return result;
    }

    void Solve(int idx, string curr, const vector<string>& arr, int& result)
    {
        unordered_set<char> currSet(curr.begin(), curr.end());
        
        if (currSet.size() != curr.length()) { return; }

        result = max(result, (int)curr.length());

        for (size_t i = idx; i < arr.size(); ++i)
        {
            Solve(i + 1, curr + arr[i], arr, result);

        }


    }


};

int main()
{
    Solution s;
    vector<string> a = { "cha","r","act","ers" };
    s.maxLength(a);
    return 0;
}