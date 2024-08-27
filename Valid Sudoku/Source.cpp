#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        bool validDigits = CheckDigitsRow(board);
        bool validDigitsColumn = CheckDigitsColumn(board);
        bool checkGrid = CheckGrid(board);


        return validDigits && validDigitsColumn && checkGrid;
    }

private:
    bool CheckDigitsRow(const vector<vector<char>>& board)
    {
        bool result = true;

        for (const auto& vec : board)
        {
            unordered_map<char, bool> seen;
            for (const auto& c : vec)
            {
                // ignore empty areas
                if (c == '.') { continue; }

                // check if valid in 1-9 range
                if (c < 49 || c > 57)
                {
                    result = false;
                    break;
                }
                // check dupes
                if (seen.count(c) >= 1)
                {
                    result = false;
                    break;
                }
                else
                {
                    seen[c] = true;
                }


            }
        }
        return result;
    }
    bool CheckDigitsColumn(const vector<vector<char>>& board)
    {
        bool result = true;
        int column = 0;
        int row = 0;


        while (column < board.size())
        {
            unordered_map<char, bool> seen;

            while (row < board.size())
            {
                // ignore empty areas
                if (board[row][column] == '.') { ++row; continue; }

                // check if valid in 1-9 range
                if (board[row][column] < 49 || board[row][column] > 57)
                {
                    result = false;
                    break;
                }
                // check dupes
                if (seen.count(board[row][column]) >= 1)
                {
                    result = false;
                    break;
                }
                else
                {
                    seen[board[row][column]] = true;
                }
                ++row;
            }
            row = 0;
            ++column;
            
        }

        return result;
    }
    bool CheckGrid(const vector<vector<char>>& board)
    {
        bool result = true;
        int start = 0, end = 3;

        int frst = 0, sec = 3;

        for (size_t i = 0; i < board.size(); ++i)
        {
            vector<vector<char>> currGrid;

            if (end > board.size())
            {
                start = 0;
                end = 3;

                frst += 3;
                sec += 3;

            }
            for (size_t j = frst; j < sec; ++j)        
            {
                currGrid.push_back({ board[j].begin() + start, board[j].begin() + end });
                if (currGrid.size() == 3)
                {
                    if (CheckDuplicateGrid(currGrid))
                    {
                        start += 3;
                        end += 3;
                    }
                    else
                    {
                        return false;

                    }
                }


            }


            
        }


        return result;
    }
    bool CheckDuplicateGrid(const vector<vector<char>>& board)
    {
        bool result = true;
        unordered_map<char, bool> seen;
        for (const auto& vec : board)
        {
            for (const auto& c : vec)
            {
                // ignore empty areas
                if (c == '.') { continue; }

                // check if valid in 1-9 range
                if (c < 49 || c > 57)
                {
                    result = false;
                    break;
                }
                // check dupes
                if (seen.count(c) >= 1)
                {
                    result = false;
                    break;
                }
                else
                {
                    seen[c] = true;
                }


            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> board =
    {
        {
        {'.','.','.','.','5','.','.','1','.'},
        {'.','4','.','3','.','.','.','.','.'},
        {'.','.','.','.','.','3','.','.','1'},
        {'8','.','.','.','.','.','.','2','.'},
        {'.','.','2','.','7','.','.','.','.'},
        {'.','1','5','.','.','.','.','.','.'},
        {'.','.','.','.','.','2','.','.','.'},
        {'.','2','.','9','.','.','.','.','.'},
        {'.','.','4','.','.','.','.','.','.'}
        }
    };
    cout << s.isValidSudoku(board);

    return 0;
}