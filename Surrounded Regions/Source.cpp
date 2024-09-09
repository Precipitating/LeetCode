#include <iostream>
#include <vector>
using namespace std;


class Solution
{
public:
    void solve(vector<vector<char>>& board) 
    {
        // temp mark borders & neighbours safe, as borders cannot be surrounded,
        // so the region won't be converted ever.
        for (int i = 0; i < board[0].size(); ++i)
        {
            // rows
            RecursionCheck(0, i, board);
            RecursionCheck(board.size() - 1, i, board);

        }
        for (int i = 0; i < board.size(); ++i)
        {
            // cols
            RecursionCheck(i, 0, board);
            RecursionCheck(i,board[0].size() - 1, board);

        }

        // turn all O's to X
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }


            }

        }

        // turn all # to O
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] == '#')
                {
                    board[i][j] = 'O';
                }


            }

        }


    }

    // turn all neighbouring O's into #
    void RecursionCheck(int row, int col, vector<vector<char>>& board)
    {
        if (row >= board.size() || col >= board[0].size() || row < 0 || col < 0)
        {
            return;
        }

        char temp = 'O';
        char visited = '#';

        if (board[row][col] == 'O')
        {
            board[row][col] = visited;
            RecursionCheck(row + 1, col, board);
            RecursionCheck(row - 1, col, board);
            RecursionCheck(row, col + 1, board);
            RecursionCheck(row, col - 1, board);

        }




    }

};




int main()
{
    Solution s;
    vector<vector<char>> board = { {'X','O','X','O','X','O'},{'O','X','O','X','O','X'},{'X','O','X','O','X','O'},{'O','X','O','X','O','X'} };
    s.solve(board);
    return 0;
}