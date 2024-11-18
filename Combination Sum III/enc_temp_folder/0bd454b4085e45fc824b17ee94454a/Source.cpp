#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<vector<int>> result;
        vector<int> curr; 
        BackTrack(1, 0, curr, k, n, result);
        return result;
    }

    void BackTrack(int idx, int sum, vector<int>& curr, int k, int n, vector<vector<int>>& result)
    {
        if (sum > n) { return; }
        if (curr.size() == k)
        {
            if (sum == n)
            {
                result.push_back(curr);
            }
            return;
        }
        if (idx > 9) { return; }
        curr.push_back(idx);
        BackTrack(idx + 1, sum + idx, curr, k, n, result);
        curr.pop_back();
        BackTrack(idx + 1, sum, curr, k, n, result);



    }
};
int main()
{
    Solution s;
    s.combinationSum3(9, 45);
    return 0;
}