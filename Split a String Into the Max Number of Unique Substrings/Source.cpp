#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution 
{
public:
    int maxUniqueSplit(string s) 
    {
        unordered_set<string> visited;
        int result = 0;

        Solve(0, 0, s, visited, result);
        return result;
    }

    void Solve(int idx, int count, const string& s, unordered_set<string>& visited, int& result)
    {
        if (idx == s.size()) { result = max(result, count); return; }


        for (size_t i = idx + 1; i <= s.size(); ++i)
        {
            string curr = s.substr(idx, i - idx);

            // backtrack
            if (!visited.count(curr))
            {
                visited.insert(curr);
                Solve(i, count + 1, s, visited, result);
                visited.erase(curr);
            }
        }

    }
};

int main()
{
    Solution s;
    s.maxUniqueSplit("ababccc");
    return 0;
}