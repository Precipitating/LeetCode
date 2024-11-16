#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> result;
        vector<int> curr;
        BackTrack(1, n, k, curr, result);
        return result;
    }
    void BackTrack(int idx, int n, int k, vector<int>& curr, vector<vector<int>>& result)
    {
        if (k == curr.size())
        {
            result.push_back(curr);
            return;
        }

        if (idx > n) { return; }

        curr.push_back(idx);
        BackTrack(idx + 1, n, k, curr, result);
        curr.pop_back();
        BackTrack(idx + 1, n, k, curr, result);


    }
};

int main()
{
    Solution s;
    s.combine(4, 2);
    return 0;

}