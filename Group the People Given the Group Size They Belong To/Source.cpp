#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) 
    {
        vector<vector<int>> result;
        unordered_map<int, vector<int>> groups;

        for (size_t i = 0; i < groupSizes.size(); ++i)
        {      
            groups[groupSizes[i]].push_back(i);

            // group is full, push back to empty it
            if (groups[groupSizes[i]].size() == groupSizes[i])
            {
                result.push_back(groups[groupSizes[i]]);
                groups[groupSizes[i]].clear();

            }

        }

        return result;
    }
};


int main()
{
    Solution s;
    vector<int> grpSize = { 3,3,3,3,3,1,3 };
    s.groupThePeople(grpSize);
    return 0;
}
