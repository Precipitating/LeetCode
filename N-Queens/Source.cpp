#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution 
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        vector<bool> cols(n);
        vector<bool> diagonal(2 * n - 1);
        vector<bool> adiagonal(2 * n - 1);

        BackTrack(n,0, result,board, cols, diagonal, adiagonal);

        return result;

    }

    void BackTrack(int n, int row, vector<vector<string>>& result, vector<string>& board, vector<bool>& c, vector<bool>& d, vector<bool>& ad)
    {
        if (row == n) { result.push_back(board);  return; }
        // row
        for (size_t col = 0; col < n; ++col)
        {
            if (c[col] || d[row - col + n] || ad[row + col]) {continue;}

            board[row][col] = 'Q';
            c[col] = true;
            d[row - col + n] = true; // left -> right diagonal
            ad[row + col] = true; // right -> left diagonal

            BackTrack(n, row+1, result,board, c, d, ad);

            board[row][col] = '.';
            c[col] = false;
            d[row - col + n] = false;
            ad[row + col] = false;

        }


    }


};


int main()
{
    Solution s;
    s.solveNQueens(4);
    return 0;
}
