#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2)
    {
        int answer = 0;
        // remove all grid2 islands if its connected to a node that doesn't match grid1's.
        for (size_t i = 0; i < grid2.size(); ++i)
        {
            for (size_t j = 0; j < grid2[0].size(); ++j)
            {
                if (grid2[i][j] == 1 && grid1[i][j] == 0)
                {
                    DFS(grid1, grid2, i, j);
                }
            }
        }
        
        // count all islands
        for (size_t i = 0; i < grid2.size(); ++i)
        {
            for (size_t j = 0; j < grid2[0].size(); ++j)
            {
                if (grid2[i][j])
                {
                    DFS(grid1, grid2, i, j);
                    ++answer;
                }
            }
        }

        return answer;
    }

    void DFS(const vector<vector<int>>& grid1, vector<vector<int>>& grid2, int x, int y)
    {
        if (x < 0 || x >= grid2.size() || y < 0 || y >= grid2[0].size())
        {
            return;
        }

        if (grid2[x][y] == 0) { return; }

        grid2[x][y] = 0;
        DFS(grid1, grid2, x + 1, y);
        DFS(grid1, grid2, x - 1, y);
        DFS(grid1, grid2, x, y + 1);
        DFS(grid1, grid2, x, y - 1);

      







    }

};


int main()
{
    Solution s;
    vector<vector<int>> grid1 = { {1,1,1,1,0,0} ,{1,1,0,1,0,0},{1,0,0,1,1,1},{1,1,1,0,0,1},{1,1,1,1,1,0},{1,0,1,0,1,0},{0,1,1,1,0,1},{1,0,0,0,1,1},{1,0,0,0,1,0},{1,1,1,1,1,0} };
    vector<vector<int>> grid2 = { {1,1,1,1,0,1} ,{0,0,1,0,1,0},{1,1,1,1,1,1},{0,1,1,1,1,1},{1,1,1,0,1,0},{0,1,1,1,1,1},{1,1,0,1,1,1},{1,0,0,1,0,1},{1,1,1,1,1,1},{1,0,0,1,0,0} };
    s.countSubIslands(grid1, grid2);

   return 0;
};
