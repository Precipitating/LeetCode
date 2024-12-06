#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    bool canPartitionKSubsets(vector<int>& nums, int k)
    {
        vector<bool> visited(nums.size(), false);
        // not divisible = cant split subset k times
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if ((totalSum % k) != 0 || nums.size() < k) { return false; }

        // better pruning if we start from highest num to lowest
        sort(nums.rbegin(), nums.rend());
        return Solve(0, totalSum / k, 0, nums, visited, k);

    }

    bool Solve(int idx, int target, int sum, const vector<int>& nums, vector<bool>& visited, int k)
    {
        if (idx > nums.size()) { return false; }
        if (k == 0) { return true; }
        if (sum == target)
        {
            return Solve(0, target, 0, nums, visited, k - 1);
        }

        for (size_t i = idx; i < nums.size(); ++i)
        {
            if (visited[i] || sum + nums[i] > target) { continue; }

            visited[i] = true;
            if (Solve(i + 1, target, sum + nums[i], nums, visited, k)) { return true; }
            visited[i] = false;

        }

        return false;
    }

};

int main()
{
    Solution s;
    vector<int> nums = { 4,3,2,3,5,2,1 };
    s.canPartitionKSubsets(nums, 4);
    return 0;
}