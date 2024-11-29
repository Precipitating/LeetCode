#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution
{
public:
    int minSessions(vector<int>& tasks, int sessionTime) 
    {
        int result = INT_MAX;
        vector<int> groups;

        Solve(0, tasks, sessionTime, groups, result);

        return result;

    }

    void Solve(int idx, const vector<int>& tasks, int target, vector<int>& groups, int& result)
    {
        if (idx >= tasks.size())
        {
            result = min(result, (int)groups.size());
            return;
        }
        if (groups.size() > result) { return; }


        // add to current group
        for (int i = 0; i < groups.size(); ++i)
        {
            if (groups[i] + tasks[idx] <= target)
            {
                groups[i] += tasks[idx];
                Solve(idx + 1, tasks, target, groups, result);
                groups[i] -= tasks[idx];
            }
        }

        // or add to new group
        groups.push_back(tasks[idx]);
        Solve(idx + 1, tasks, target, groups, result);
        groups.pop_back();




    }
};

int main()
{
    Solution s;
    vector<int> tasks = { 3,1,3,1,1 };
    s.minSessions(tasks, 8);
    return 0;
}