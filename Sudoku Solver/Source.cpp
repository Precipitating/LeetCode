#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    void solveSudoku(vector<vector<char>>& board) 
    {
        BackTrack(board);
    }


    bool BackTrack(vector<vector<char>>& board)
    {
        for (size_t i = 0; i < board.size(); ++i)
        {
            for (size_t j = 0; j < board[i].size(); ++j)
            {
                if (board[i][j] == '.')
                {
                    // attempt every digit
                    for (char c = '1'; c <= '9'; ++c)
                    {
                        if (IsValid(i, j, board, c))
                        {
                            board[i][j] = c;
                            if (BackTrack(board))
                            {
                                return true;
                            }
                            else
                            {
                                board[i][j] = '.';
                            }

                        }
                        
                    }
                    return false;


                }

            }
        }
        return true;


    }
    bool IsValid(int row, int col, const vector<vector<char>>& board, char num)
    {
        bool result = true;
        for (size_t i = 0; i < 9; ++i)
        {
            // check rol, col and 3x3 grid
            if (board[row][i] == num || board[i][col] == num || board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num) { result = false; break; }

        }

        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> board =
    {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    s.solveSudoku(board);

    return 0;
}