#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void rotate(vector<vector<int>>& matrix)
    {
        // tranpose the matrix
        TransposeMatrix(matrix);
        
        // reverse rows
        for (size_t i = 0; i < matrix.size(); ++i)
        {
            int first = 0, last = matrix.size() - 1;
            while (first < last)
            {
                swap(matrix[i][first], matrix[i][last]);
                ++first;
                --last;
            }
        }

    }
private:
    void TransposeMatrix(vector<vector<int>>& matrix)
    {
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};


int main()
{
    Solution s;
    vector<vector<int>> matrix = { {1,2,3} ,{4,5,6},{7,8,9} };
    s.rotate(matrix);
    return 0;
}