#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings)
    {
        int currHeight = 0;
        vector<vector<int>> result;
        vector<pair<int,int>> points;

        multiset<int> multiSet;
        multiSet.insert(0);


        for (const vector<int>& building : buildings)
        {
            // start, -ve ensures its the start
            points.emplace_back(building[0], -building[2]);
            // end
            points.emplace_back(building[1], building[2]);

            
        }

        sort(points.begin(), points.end());



        for (int i = 0; i < points.size(); ++i)
        {
            int xCoord = points[i].first;
            int pointHeight = points[i].second;

            // if we have a starting point, add to set (fallback)
            if (pointHeight < 0)
            {
                // back to +ve
                multiSet.insert(-pointHeight);
            }
            else
            {
                multiSet.erase(multiSet.find(pointHeight));
            }

            // check if largest height in set has a change
            int currentMaxHeight = *multiSet.rbegin();

            if (currHeight != currentMaxHeight)
            {
                currHeight = currentMaxHeight;
                result.push_back({ xCoord, currHeight });
            }

        }




        return result;

    }
};


int main()
{
    Solution s;
    vector<vector<int>> buildings = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    s.getSkyline(buildings);
    return 0;
}