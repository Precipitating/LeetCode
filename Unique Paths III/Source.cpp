#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    int uniquePathsIII(vector<vector<int>>& grid)
    {
        int result = 0;
        int stepsReq = 0;
        int startingPosX = 0;
        int startingPosY = 0;
        // get steps required & starting pos
        for (size_t i = 0; i < grid.size(); ++i)
        {
            for (size_t j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    startingPosX = i;
                    startingPosY = j;
                }
                if (grid[i][j] != -1)
                {
                    ++stepsReq;
                }

            }
        }

        Solve(startingPosX, startingPosY, stepsReq, grid, result);
        return result;
    }

    void Solve(int row, int col, int cnt,vector<vector<int>>& grid, int& result)
    {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) { return; }
        if (grid[row][col] == -1) { return; }
        if (cnt == 1 && grid[row][col] == 2) { ++result; return; }
        if (grid[row][col] == 2 && cnt != 1) { return; }

        int storedNum = grid[row][col];              
        if (grid[row][col] != 9)
        {
            grid[row][col] = 9;
            Solve(row + 1, col, cnt - 1, grid, result);
            Solve(row - 1, col, cnt - 1, grid, result);
            Solve(row, col + 1, cnt - 1, grid, result);
            Solve(row, col - 1, cnt - 1, grid, result);
            grid[row][col] = storedNum;
        }

    }
};



int main()
{
    Solution s;
    vector<vector<int>> grid = { {0,1},{2,0 } };
    s.uniquePathsIII(grid);

    return 0;
}