#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution
{
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node)
    {
        priority_queue<pair<double, int>> maxHeap;
        unordered_set<int> visited;
        unordered_map<int, vector<pair<int, double>>> map;

        // add to map for faster access
        for (size_t i = 0; i < edges.size(); ++i)
        {
            map[edges[i][0]].push_back({ edges[i][1], succProb[i]});
            map[edges[i][1]].push_back({ edges[i][0], succProb[i]});
        }

        // add default value, 1 as multiplying by 1 at start will get the first probability.
        maxHeap.push({ 1,start_node });

        while (!maxHeap.empty())
        {
            auto [prob,currentNode] = maxHeap.top();
            visited.insert(currentNode);
            maxHeap.pop();

            // exit condition, the moment currentNode is end node as prio queue puts top probability automatically.
            // which should be the answer
            if (currentNode == end_node)
            {
                return prob;
            }

            // for every possible node we can visit on current node,
            // multiply current probably with next probability
            for (const auto& [nextNode, nextProb] : map[currentNode])
            {
                if (visited.count(nextNode) == 0)
                {
                    maxHeap.push({ prob * nextProb, nextNode });
                }
            }


        }
        return 0;
    }



};

int main()
{
    Solution s;
    int n = 3;
    int start = 0, end = 2;
    vector<vector<int>> edges = { {0,1},{1,2},{0,2}};
    vector<double> success = { 0.5,0.5,0.2 };
    std::cout << s.maxProbability(n, edges, success, start, end);



    return 0;
}