#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> constructDistancedSequence(int n)
    {
        vector<int> result((n * 2) - 1);
        vector<bool> visited(n + 1, false); // Track visited numbers
        Solve(0, n, result, visited);



        return result;
    }

    bool Solve(int idx, int n, vector<int>& result, vector<bool>& visited)
    {
        if (idx >= result.size()) { return true; }
        if (result[idx] != 0)
        {
            return Solve(idx + 1, n, result, visited);
        }

        for (int i = n; i >= 1; --i)
        {
            if (visited[i]) { continue; }
            if (i != 1 && ((idx + i) >= result.size() || result[idx + i])) { continue; }

            result[idx] = i;
            visited[i] = true;


            // back track
            if (i != 1)
            {
                result[idx + i] = i;
            }

            if (Solve(idx + 1, n, result, visited))
            {
                return true;
            }

            result[idx] = 0;
            visited[i] = false;
            if (i != 1)
            {
                result[idx + i] = 0;
            }



        }

        return false;


    }
};

int main()
{
    Solution s;
    s.constructDistancedSequence(4);
    return 0;
}