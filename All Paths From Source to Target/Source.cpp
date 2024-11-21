#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        vector<vector<int>> result;
        vector<int> curr;
        curr.push_back(0);
        DFS(0, curr, graph, result);

        return result;
    }

    void DFS(int idx, vector<int>& curr, const vector<vector<int>>& graph, vector<vector<int>>& result)
    {
        if (idx == graph.size() - 1)
        {
            result.push_back(curr);
            return;
        }


        for (int num : graph[idx])
        {
            curr.push_back(num);
            DFS(num, curr, graph, result);
            curr.pop_back();
        }


    }
};

int main()
{
    Solution s;
    vector<vector<int>> graph = { {1,2},{3},{3},{} };
    s.allPathsSourceTarget(graph);
    return 0;
}