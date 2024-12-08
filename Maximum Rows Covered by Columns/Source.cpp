#include <iostream>
#include <vector>
#include <bit>
using namespace std;

class Solution
{
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect)
    {
        for (int mask = 1; mask < (1 << matrix[0].size()); ++mask)
        {
            // count the 1's in the bitmask
            // this determines if numSelect columns are selected
            if (popcount((unsigned)mask) == numSelect)
            {
                // mark all rows valid initially
                int visited = matrix.size();

                for (int i = 0; i < matrix.size(); ++i)
                {
                    for (int j = 0; j < matrix[0].size(); ++j)
                    {
                        // if column not selected & required column not selected,
                        // its invalid
                        // we go in reverse order due to LSB in bits
                        if (!(mask & (1 << j)) && matrix[i][matrix[0].size() - j - 1] == 1)
                        {
                            --visited;
                            break;
                        }
                    }
                }

                result = max(result, visited);
            }


        }



        return result;
    }


private:
    int result = 0;
};

int main()
{
    Solution s;
    vector<vector<int>> matrix = { {0,0,0}, {1,0,1}, {0,1,1}, {0,0,1} };
    s.maximumRows(matrix, 2);
    return 0;
}