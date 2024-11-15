#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<vector<int>> result;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        BackTrack(0, 0,candidates, curr, target, result);
        return result;
    }

    void BackTrack(int idx, int currSum, const vector<int>& candidates, vector<int>& curr, int target, vector<vector<int>>& result)
    {
        if (currSum > target) { return; }

        if (currSum == target)
        {
            result.push_back(curr);
            return;
        }

        for (int i = idx; i < candidates.size(); ++i)
        {
            if (i > idx && candidates[i] == candidates[i - 1])
            {
                continue;
            }
            curr.push_back(candidates[i]);
            BackTrack(i + 1, currSum + candidates[i], candidates, curr, target, result);
            curr.pop_back();

        }
    }
};

int main()
{
    Solution s;
    vector<int> comb = { 10,1,2,7,6,1,5 };
    s.combinationSum2(comb, 8);

    return 0;
}