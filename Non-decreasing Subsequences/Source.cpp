#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        vector<int> curr;
        
        Solve(0, curr, nums);

        return vector<vector<int>>(result.begin(), result.end());
    }

    void Solve(int idx, vector<int>& curr, const vector<int>& nums)
    {
        if (idx == nums.size()) 
        {
            if (curr.size() > 1)
            {
                result.insert(curr);
            }

            return;
        }

        if (curr.empty() || nums[idx] >= curr.back())
        {
            curr.push_back(nums[idx]);
            Solve(idx + 1, curr, nums);
            curr.pop_back();
            Solve(idx + 1, curr, nums);
        }



    }

private:
    set<vector<int>> result;

};

int main()
{
    Solution s;
    vector<int> num = { 4,6,7,7 };
    s.findSubsequences(num);

    return 0;
}