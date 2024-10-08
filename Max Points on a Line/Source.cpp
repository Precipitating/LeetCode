#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;


class Solution 
{
public:
    int maxPoints(vector<vector<int>>& points) 
    {
        int maxVal = 0;
        

        for (size_t i = 0; i < points.size(); ++i)
        {   
            unordered_map<double, int> groupedLines;
            int verticalSlopes = 0;
            for (size_t j = i+1; j < points.size(); ++j)
            {
                // form a potential line start
                pair<int, int> point1 = { points[i][0],points[i][1] };
                pair<int, int> point2 = { points[j][0],points[j][1] };

                // get slope

                double xDiff = point2.first - point1.first;
                double yDiff = point2.second - point1.second;
                double ans = yDiff / xDiff;

                if (xDiff != 0)
                {
                    ++groupedLines[ans];    
                }
                else
                {
                    ++verticalSlopes;
                }

                maxVal = max(maxVal, max(verticalSlopes,groupedLines[ans]));


            }
        }
        return maxVal + 1;


    }
};

int main()
{
    vector<vector<int>> points = { {1,1},{3,2},{5,3},{4,1},{2,3},{1,4} };
    Solution s;
    cout << s.maxPoints(points);

    return 0;
}