#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Solution 
{
public:
    vector<int> smallestRange(vector<vector<int>>& nums) 
    {
        if (nums.empty()) { return {}; }
        vector<int> result;
        vector<pair<int,int>> merged;

        // merge the lists and put an identifier on each list 
        // first = num
        // second = idx
        for (int i = 0; i < nums.size(); ++i)
        {
            for (const int& num : nums[i])
            {
                merged.emplace_back(num, i);

            }
        }
        sort(merged.begin(), merged.end());

        unordered_map<int, int> count;

        int left = 0, right = 0;

        for (int i = 0; i < merged.size(); ++i)
        {
            if (!count[merged[i].second]++) { ++right; }

            // if current sliding window contains an elem from every list...
            if (right == nums.size())
            {
                // shrink left to get smallest range 
                while (count[merged[left].second] > 1) { --count[merged[left++].second]; }

                // update range if smaller one is found
                if (result.empty() || result[1] - result[0] > merged[i].first - merged[left].first)
                {
                    result = vector<int>{ merged[left].first, merged[i].first };
                }


            }
        }



        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> nums = { {4,10,15,24,26},{0,9,12,20}, {5,18,22,30} };
    s.smallestRange(nums);
    return 0;
}