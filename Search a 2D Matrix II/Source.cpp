#include <iostream>
#include <vector>
using namespace std;


class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        bool result = false;
        // find potential row of where the target may be
        int row = 0;
        int col = matrix[0].size() - 1;

        while (row < matrix.size() && row >= 0 && col < matrix[0].size() && col >= 0)
        {
            if (matrix[row][col] > target)
            {
                --col;
            }
            else if (matrix[row][col] < target)
            {
                ++row;
            }
            else
            {
                result = true;
                break;
            }
        }

        return result;
        
    }
};


int main()
{
    Solution s;
    vector<vector<int>> matrix = { {1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30} };
    cout << s.searchMatrix(matrix, 91);

    return 0;
}