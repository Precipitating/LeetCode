#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    struct pair_hash
    {
        template <class T1, class T2>
        std::size_t operator () (const std::pair<T1, T2>& p) const {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);
            return h1 ^ h2; // Combine the two hashes
        }
    };
    void setZeroes(vector<vector<int>>& matrix)
    {
        unordered_set<pair<int,int>, pair_hash> marked;
        // mark positions to be zeroed out
        for (int row = 0; row < matrix.size(); ++row)
        {
            for (int col = 0; col < matrix[0].size(); ++col)
            {
                if (matrix[row][col] == 0)
                {
                    marked.insert({row,col});

                }
                
            }
        }

        for (const auto& it : marked)
        {
            RecursiveColumn(matrix, it.first, 0);
            RecursiveRow(matrix, 0, it.second);

        }


    }


    void RecursiveColumn(vector<vector<int>>& matrix, int row, int col)
    {
        if (col >= matrix[0].size()) { return; }


        matrix[row][col] = 0;

        RecursiveColumn(matrix, row, col + 1);


    }

    void RecursiveRow(vector<vector<int>>& matrix, int row, int col)
    {
        if (row >= matrix.size() || row < 0) { return; }

        matrix[row][col] = 0;

        RecursiveRow(matrix, row + 1, col);


    }
};


int main()
{
    Solution s;
    vector<vector<int>> matrix = { {0,1,2,0},{3,4,5,2},{1,3,1,5 } };
    s.setZeroes(matrix);

    return 0;
}