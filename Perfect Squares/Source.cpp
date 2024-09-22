#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution 
{
public:
    int numSquares(int n)
    {
        int result = 0;
        vector<int> squares; 
        queue<pair<int,int>> q;
        unordered_set<int> visited;

        for (int i = 1; i * i <= n; ++i) 
        {
            squares.push_back(i * i);
        }

        q.emplace(0, 0);
        visited.insert(0);

        while (!q.empty())
        {
            pair<int, int> curr = q.front(); q.pop();

            for (size_t i = 0; i < squares.size(); ++i)
            {
                int nextSum = curr.first + squares[i];


                if (nextSum == n) { return curr.second + 1; }

                if (nextSum < n && visited.find(nextSum) == visited.end())
                {
                    q.emplace(nextSum,curr.second + 1);
                    visited.insert(nextSum);
                }

            }

        }

        return 0;
        
    }
};


int main()
{
    Solution s;
    cout << s.numSquares(13);
    return 0;
}