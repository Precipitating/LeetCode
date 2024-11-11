#include <iostream>
#include <vector>
using namespace std;
class Solution 
{
public:
    int maximumGood(vector<vector<int>>& statements) 
    {
        result = 0;
        n = statements.size();
        string curr = "";
        DFS(0, 0, curr, statements);
        return result;
    }

    void DFS(int idx, int goodCount, const string& curr, const vector<vector<int>>& statements)
    {
        if (idx == n)
        {
            if (IsValid(curr, statements))
            {
                result = max(result, goodCount);
                
            }
            return;
        }
        // assume current person is good and DFS
        DFS(idx + 1, goodCount + 1, curr + '1', statements);
        // now assume bad
        DFS(idx + 1, goodCount, curr + '0', statements);



    }

    bool IsValid(const string& curr, const vector<vector<int>>& statements)
    {
        for (size_t i = 0; i < n; ++i)
        {
            // 1 == good
            if (curr[i] == '1')
            {
                // check if statements is same as curr
                for (size_t j = 0; j < n; ++j)
                {
                    if (statements[i][j] != 2 && statements[i][j] != (curr[j] - '0'))
                    {
                        return false;
                    }
                }
            }

            
        }
        return true;
    }

private:
    int n;
    int result;
};


int main()
{
    Solution s;
    vector<vector<int>> state = { {2,1,2},{1,2,2},{2,0,2} };
    s.maximumGood(state);
    return 0;
}