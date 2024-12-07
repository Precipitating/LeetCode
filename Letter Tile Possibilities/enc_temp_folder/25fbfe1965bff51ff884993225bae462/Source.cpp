#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int numTilePossibilities(string tiles)
    {
        string curr;
        vector<bool> visited(tiles.size(), false);
        sort(tiles.begin(), tiles.end());
        Solve(curr, tiles, visited);

        return result;
    }

    void Solve(string& curr, const string& tiles, vector<bool>& visited)
    {
        if (!curr.empty())
        {
            ++result;
        }

        for (size_t i = 0; i < tiles.size(); ++i)
        {
            // skip dupes and visited
            if (visited[i] || (i > 0 && tiles[i] == tiles[i - 1] && !visited[i - 1]))
            {
                continue;
            }

            visited[i] = true;
            curr += tiles[i];

            Solve(curr, tiles, visited);

            visited[i] = false;
            curr.pop_back();


        }







    }

private:
    int result = 0;
};


int main()
{
    Solution s;
    s.numTilePossibilities("AAB");
    return 0;
}