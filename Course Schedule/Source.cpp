#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        bool result = false;
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);

        // store node link values and counts
        for (const auto& preq : prerequisites)
        {
            adj[preq[1]].push_back(preq[0]);
            ++indegree[preq[0]];

        }

        // fill queue with nodes with 0 indegree val
        queue<int> q;
        for (size_t i = 0; i < numCourses; ++i)
        {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int visited = 0;
        while (!q.empty())
        {
            // visit and remove 0 indegree node
            int val = q.front(); q.pop();
            ++visited;

            // check neighbours of current node and remove all neighbours
            for (const auto& neighbour : adj[val])
            {
                --indegree[neighbour];

                // add to queue if neighbour is 0 after decrement
                if (indegree[neighbour] == 0)
                {
                    q.push(neighbour);
                }
            }

        }


        return numCourses == visited;
    }
};


int main()
{
    Solution s;
    vector<vector<int>> preq = { {1,0},{1,2},{2,3},{2,4},{2,5},{3,1},{4,5} };
    int numCourses = 6;
    cout << s.canFinish(numCourses, preq);

    return 0;
}