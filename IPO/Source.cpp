#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital)
    {
        priority_queue<int> maxHeap;

        // link the profit/capital values together, as we'll need them together when sorting
        vector<pair<int,int>> proj(capital.size());
        for (int i = 0; i < capital.size(); ++i)
        {
            proj[i] = { capital[i], profits[i] };
        }
        // minimum capital first
        sort(proj.begin(), proj.end());

        int idx = 0;

        while (k--)
        {
            // if our current capital is sufficent for this project
            while (idx < capital.size() && proj[idx].first <= w)
            {
                // add profit to heap and go to next project
                maxHeap.push(proj[idx].second);
                ++idx;
            }

            if (maxHeap.empty()) { break; }

            // top will always have the best profit per iteration
            w += maxHeap.top();
            maxHeap.pop();

        }

        return w;


    }

};

int main()
{
    Solution s;
    vector<int> profits = { 1,2,3 };
    vector<int> capital = { 0,1,1};
    s.findMaximizedCapital(2,0, profits, capital);
    return 0;
}