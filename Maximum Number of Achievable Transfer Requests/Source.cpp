#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maximumRequests(int n, vector<vector<int>>& requests)
    {
        result = 0;
        vector<int> indegree(n, 0);
        Solve(0, 0, n, requests, indegree);
        return result;
    }

    void Solve(int idx, int count, int n, const vector<vector<int>>& req, vector<int>& indegree)
    {
        if (idx == req.size())
        {
            // check if balanced, and if not, invalid
            for (size_t i = 0; i < n; ++i)
            {
                if (indegree[i] != 0)
                {
                    return;
                }
            }
            result = max(result, count);
            return;
        }

        // back track
        // take the req
        --indegree[req[idx][0]];
        ++indegree[req[idx][1]];
        Solve(idx + 1, count + 1, n, req, indegree);

        // dont take
        ++indegree[req[idx][0]];
        --indegree[req[idx][1]];
        Solve(idx + 1, count, n, req, indegree);


    }
private:

    int result;
};

int main()
{
    Solution s;
    vector<vector<int>> req = { {0,1},{1,0},{0,1},{1,2},{2,0},{3,4} };
    s.maximumRequests(5, req);

    return 0;
}