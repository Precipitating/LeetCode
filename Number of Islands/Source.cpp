#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int result = 0;
        vector<vector<bool>> isVisited(grid.size(), vector<bool>(grid[0].size()));

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (!isVisited[i][j] && grid[i][j] == '1')
                {
                    Solve(i, j, grid, isVisited);
                    ++result;
                }

            }
        }

        return result;
    }

    void Solve(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& visited)
    {
        if (row < 0 || row >= grid.size()) { return; }
        if (col < 0 || col >= grid[0].size()) { return; }


        if (grid[row][col] == '1' && !visited[row][col])
        {
            visited[row][col] = true;
            Solve(row + 1, col, grid, visited);
            Solve(row - 1, col, grid, visited);
            Solve(row, col + 1, grid, visited);
            Solve(row, col - 1, grid, visited);
        }



    }
};

int main()
{
    Solution s;
    vector<vector<char>> grid = { {'1','1','0','0','0'},
                                  {'1','1','0','0','0'},
                                  {'0','0','1','1','0'},
                                  {'0','0','1','1','1'} 
                                };
    cout << s.numIslands(grid);

    return 0;
}