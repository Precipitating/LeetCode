#include <iostream>
#include <string>
#include <map>
using namespace std;


class Solution
{
public:
    // Top down memoization O(mxn) complexity
    bool isMatch(string s, string p)
    {

        return dfs(0, 0, s, p);


    }

    // depth first search
    bool dfs(int i, int j, const string& s, const string& p)
    {
        if (cache.count(make_pair(i, j)) == 1)
        {
            return cache[make_pair(i, j)];
        }

        // edge cases
        if (i >= s.length() && j >= p.length()) { return true; }
        if (j >= p.length()) { return false; }

        // if s in bounds and char is . or equal..
        bool match = (i < s.length()) && (s[i] == p[j] || (p[j] == '.'));

        // if current pattern char equals * & in bounds
        if ((j + 1) < p.length() && p[j + 1] == '*')
        {
            cache[make_pair(i,j)] = (dfs(i, j + 2, s, p) || (match && dfs(i + 1, j, s, p)));
            return cache[make_pair(i, j)];

        }
        if (match)
        {
            cache[make_pair(i, j)] = dfs(i + 1, j + 1, s, p);
            return cache[make_pair(i, j)];
        }
        cache[make_pair(i, j)] = false;
        return cache[make_pair(i, j)];

    }

private:
    map<pair<int, int>, bool> cache;


};



int main()
{
    Solution s;
    cout << s.isMatch("ab", ".*c");
    return 0;
}