#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) 
    {
        vector<int> visited(values.size(), 0);

        // key is the node
        // pair is: neighbour node, travel time
        // we add both directions of travel from & back to graph
        for (const auto& edge : edges)
        {
            graph[edge[0]].emplace_back(edge[1], edge[2]);
            graph[edge[1]].emplace_back(edge[0], edge[2]);
        }

        Solve(0, 0, 0, values, visited, maxTime);
        return result;
    }

    void Solve(int currNode, int currQuality, int currTime, const vector<int>& values, vector<int>& visited, int maxTime)
    {
        if (currTime > maxTime)
        {
            return;
        }

        if (visited[currNode] == 0)
        {
            currQuality += values[currNode];
        }

        if (currNode == 0)
        {
            result = max(result, currQuality);
        }

        ++visited[currNode];
        for (const auto& neigh : graph[currNode])
        {
            Solve(neigh.first, currQuality, currTime + neigh.second, values, visited, maxTime);
        }
        --visited[currNode];





    }

private:
    int result = 0;
    unordered_map<int, vector<pair<int, int>>> graph;

};

int main()
{
    Solution s;
    vector<int> vals = { 0,32,10,43 };
    vector<vector<int>> edges = { {0,1,10}, {1,2,15}, {0,3,10} };
    int maxTime = 49;
    s.maximalPathQuality(vals, edges, maxTime);

    return 0;
}