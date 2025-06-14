#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> row = { 1 };

        for (size_t i = 1; i <= rowIndex; ++i)
        {
            row.push_back(1);
            for (size_t j = i - 1; j > 0; --j)
            {
                row[j] = row[j] + row[j - 1];
            }
        }


        return row;
    }
};

int main()
{
    Solution s;
    s.getRow(3);


	return 0;
}