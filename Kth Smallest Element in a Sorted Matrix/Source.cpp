#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        // binary search 
        
        // define search space for values
        int minVal = matrix[0][0];
        int maxVal = matrix[matrix.size() - 1][matrix.size() - 1];

        while (minVal < maxVal)
        {
            int count = 0;
            // get median
            int mid = minVal + (maxVal - minVal) / 2;

            // count how many numbers <= k in each row
            for (size_t i = 0; i < matrix.size(); ++i)
            {
                // get first index of where it is >= median, and add to count (per row)
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            
            // increase value range if < k
            if (count < k)
            {
                minVal = mid + 1;

            }
            else
            {
                maxVal = mid;
            }



        }

        return minVal;
    }

};


int main()
{
    Solution s;
    vector<vector<int>> matrix = { {1,5,9},{10,11,13},{12,13,15} };
    s.kthSmallest(matrix, 8);
    return 0;
}


