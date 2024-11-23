#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int getMaximumGold(vector<vector<int>>& grid) 
    {
        int result = 0;

        for (size_t i = 0; i < grid.size(); ++i)
        {
            for (size_t j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 0) { continue; }
                Solve(i, j, 0, grid, result);
            }
        }


        return result;

    }

    void Solve(int row, int col, int currGold, vector<vector<int>>& grid, int& result)
    {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) { return; }
        if (grid[row][col] == 0) { return; }

        int currVal = grid[row][col];
        grid[row][col] = 0;
        Solve(row + 1, col, currGold + currVal, grid, result);
        Solve(row - 1, col, currGold + currVal, grid, result);
        Solve(row, col + 1, currGold + currVal, grid, result);
        Solve(row, col - 1, currGold + currVal, grid, result);
        result = max(result, currGold + currVal);

        grid[row][col] = currVal;



    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid = { {1,0,7} ,{2,0,6},{3,4,5},{0,3,0},{9,0,20} };
    s.getMaximumGold(grid);
    return 0;
}