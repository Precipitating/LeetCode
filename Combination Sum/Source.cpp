#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> result;
        vector<int> curr;
        
        BackTrack(0,0, candidates,curr, result, target);

        return result;
    }


    void BackTrack(int idx, int currSum, const vector<int>& cand, vector<int>& currVec, vector<vector<int>>& result, int target)
    {
        if (currSum == target)
        {
            result.push_back(currVec);
            return;
        }

        if (idx == cand.size() || currSum < 0 || currSum > target)
        {
            return;
        }

        currVec.push_back(cand[idx]);
        BackTrack(idx,currSum + cand[idx], cand, currVec,result,target);
        currVec.pop_back();
        BackTrack(idx+1,currSum, cand, currVec, result, target);

    }
};

int main()
{
    Solution s;
    vector<int> cand = { 8,7,4,3 };
    s.combinationSum(cand, 11);
    return 0;
}