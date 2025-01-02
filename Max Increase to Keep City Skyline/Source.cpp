#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid)
    {
        int result = 0;
        vector<int> rows(grid.size()), cols(grid.size());

        for (int i = 0; i < grid.size(); ++i) 
        {
            // get max of each row/col
            for (int j = 0; j < grid[0].size(); ++j) 
            {
                rows[i] = max(rows[i], grid[i][j]);
                cols[j] = max(cols[j], grid[i][j]);
            }
        }

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {

                result += min(rows[i], cols[j]) - grid[i][j];
            }
        }


        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid = { {3,0,8,4},{2,4,5,7},{9,2,6,3}, {0,3,1,0} };
    s.maxIncreaseKeepingSkyline(grid);
    return 0;
}