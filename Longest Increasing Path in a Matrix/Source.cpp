#include <iostream>
#include <queue>
using namespace std;
class Solution 
{
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        int result = 0;
        vector<vector<int>> memo(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                result = max(result, DFS(INT_MIN, i, j, matrix, memo));
            }
            
        }
        
        return result;


    }

    int DFS(int prevNum, int row, int col, const vector<vector<int>>& matrix,vector<vector<int>>& memo)
    {
        if (row < 0 || row >= matrix.size() || col < 0 || col >= matrix[0].size()) { return 0; }

        int curr = matrix[row][col];

        if (curr <= prevNum) { return 0; }
        if (memo[row][col] > 0) { return memo[row][col]; }

        int up = DFS(curr, row - 1, col, matrix, memo);
        int down = DFS(curr, row + 1, col,matrix, memo);
        int left = DFS(curr, row, col - 1,matrix, memo);
        int right = DFS(curr, row, col + 1, matrix, memo);


        memo[row][col] = 1 + max(max(up, down), max(left, right));


        return memo[row][col];

    }
};


int main()
{
    Solution s;
    vector<vector<int>> matrix = { {7, 7, 5}, {2, 4, 6}, {8, 2, 0} };
    s.longestIncreasingPath(matrix);
    return 0;
}