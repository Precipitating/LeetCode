#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        if (numRows == 1) { return vector<vector<int>>({ {1} }); }

        vector<vector<int>> triangle({ {1},{1,1} });
        triangle.reserve(numRows);
        for (size_t i = 3; i <= numRows; ++i)
        {
            vector<int> lastTriangleRow = triangle.back();
            vector<int> currRow;
            int first = 0, second = first + 1;
            currRow.resize(i);
            currRow.front() = 1; currRow.back() = 1;

            for (size_t i = 1; i < currRow.size() - 1; ++i)
            {
                currRow[i] = lastTriangleRow[first] + lastTriangleRow[second];
                ++first;
                ++second;
            }

            triangle.push_back(currRow);

        }

        return triangle;
    }
};

int main()
{
    Solution s;
    s.generate(1);


}