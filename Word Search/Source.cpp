#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        int currCharIdx = 0;
        bool answer = false;
        for (size_t i = 0; i < board.size(); ++i)
        {
            for (size_t j = 0; j < board[0].size(); ++j)
            {
                IsValid(i, j, board, word, currCharIdx,answer);

                if (answer) { break; }

            }
            if (answer) { break; }
        }

        return answer;
    }

    void IsValid(int row, int col,vector<vector<char>>& board, const string& word, int currentCharIdx, bool& answer)
    {
        if (col < 0 || col >= board[0].size()) { return; }
        if (row < 0 || row >= board.size()) { return; }
        if (board[row][col] != word[currentCharIdx]) { return; }
        if (answer) { return; }
        if (board[row][col] == '#') { return; }


        if (currentCharIdx == word.size() - 1)
        {
            answer = true;
            return;
        
        }

        char storedVal = board[row][col];
        board[row][col] = '#';

        IsValid(row + 1, col, board, word, currentCharIdx + 1, answer);
        IsValid(row - 1, col, board, word, currentCharIdx + 1, answer);
        IsValid(row, col + 1, board, word, currentCharIdx + 1, answer);
        IsValid(row, col - 1, board, word, currentCharIdx + 1, answer);
                
        board[row][col] = storedVal;
            

    }
};


int main()
{
    Solution s;
   // vector<vector<char>> board = { {'a','a','a','a'},{'a','a','a','a'} ,{'a','a','a','a'} };
    vector<vector<char>> board = { {'a','b'} };
    string word = "ba";
    s.exist(board,word);
    return 0;
}