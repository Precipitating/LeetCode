#include <iostream>
#include <vector>
using namespace std;


class Solution
{
public:
    void gameOfLife(vector<vector<int>>& board)
    {
        for (size_t i = 0; i < board.size(); ++i)
        {
            for (size_t j = 0; j < board[0].size(); ++j)
            {
                int neighbourCount = NeighbourCount(i, j, board);

                if (board[i][j] == 1)
                {
                    // under/over population death
                    if (neighbourCount == 3 || neighbourCount == 2)
                    {
                        board[i][j] += 2;
                    }

                }
                else
                {
                    if (neighbourCount == 3)
                    {
                        board[i][j] += 2;
                    }
                }

            }
        }


        for (size_t i = 0; i < board.size(); ++i)
        {
            for (size_t j = 0; j < board[0].size(); ++j)
            {
                board[i][j] /= 2;

            }
        }



    }

    int NeighbourCount(int row, int col, const vector<vector<int>>& board)
    {
        int count = 0;

        // check 8 neighbours
        if (col > 0)
        {
            // left
            if (board[row][col - 1] % 2 == 1)
            {
                ++count;
            }
            // left up
            if (row > 0)
            {
                if (board[row - 1][col - 1] % 2 ==  1)
                {
                    ++count;
                }
            }
            // left down
            if (row < board.size() - 1)
            {
                if (board[row + 1][col - 1] % 2 == 1)
                {
                    ++count;
                }
            }
        }

        if (col < board[0].size() - 1)
        {
            // right
            if (board[row][col + 1] % 2 == 1)
            {
                ++count;
            }
            // right up
            if (row > 0)
            {
                if (board[row - 1 ][col + 1] % 2 == 1)
                {
                    ++count;
                }
            }
            // right down
            if (row < board.size() - 1)
            {
                if (board[row + 1][col + 1] % 2 == 1)
                {
                    ++count;
                }
            }
        }

        // up & down

        if (row > 0)
        {
            if (board[row - 1][col] % 2 == 1)
            {
                ++count;
            }
        }

        if (row < board.size() - 1)
        {
            if (board[row + 1][col] % 2 == 1)
            {
                ++count;
            }
        }


        return count;


    }
};


int main()
{
    Solution s;
    vector<vector<int>> board = { {0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0} };
    s.gameOfLife(board);
    return 0;
}