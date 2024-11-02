#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int tilingRectangle(int n, int m) 
    {
        int minCount = INT_MAX;
        vector<vector<bool>> board(n, vector<bool>(m, false));
        BackTrack(n, m, 0, minCount, board);
        return minCount;

    }


    void BackTrack(int n, int m, int count, int &minCount, vector<vector<bool>>& board)
    {
        // ignore if its over the current minimum
        if (count > minCount) { return; }

        // find available empty cell

        int emptyX = -1, emptyY = -1;

        for (size_t i = 0; i < n; ++i)
        {
            for (size_t j = 0; j < m; ++j)
            {
                if (!board[i][j])
                {
                    emptyX = i;
                    emptyY = j;
                    break;
                }

            }

            if (emptyX != -1 && emptyY != -1) { break; }
        }

        // if still -1, then every cell is covered
        if (emptyX == -1 && emptyY == -1)
        {
            minCount = min(minCount, count);
            return;
        }


        // get largest square size possible that can be placed
        for (int i = min(n - emptyX, m - emptyY); i >= 1; --i)
        {
            // backtrack placement
            if (CanPlace(emptyX, emptyY, i, board))
            {
                Place(emptyX, emptyY, i, board, true);
                BackTrack(n, m, count + 1, minCount, board);
                Place(emptyX, emptyY, i, board, false);

            }

        }



    }

    bool CanPlace(int row, int col, int size, vector<vector<bool>>& board)
    {
        for (size_t i = row; i < row + size; ++i)
        {
            for (size_t j = col; j < col + size; ++j)
            {
                if (i >= board.size() || j >= board[0].size() || board[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }

    void Place(int row, int col, int size, vector<vector<bool>>& board, bool val)
    {
        for (size_t i = row; i < row + size; ++i)
        {
            for (size_t j = col; j < col + size; ++j)
            {
                board[i][j] = val;
            }
        }

    }
};


int main()
{

    Solution s;
    cout << s.tilingRectangle(2, 3);
    return 0;
}