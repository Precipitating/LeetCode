#include <iostream>
#include <vector>
using namespace std;


class Solution 
{
public:
    int countArrangement(int n)
    {
        vector<int> visited(n + 1);
        Solve(1, n, visited);
        return result;
    }

    void Solve(int pos, int n, vector<int>& visited)
    {
        if (pos > n) { ++result;  return; }
        for (size_t i = 1; i < n + 1; ++i)
        {
            if (!visited[i] && ((i % pos) == 0 || (pos % i) == 0))
            {
                visited[i] = true;
                Solve(pos + 1, n, visited);
                visited[i] = false;
            }
        }
    }

private:
    int result = 0;
};

int main()
{
    Solution s;
    s.countArrangement(2);
    return 0;
}