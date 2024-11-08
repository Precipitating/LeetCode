#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int maxScore(vector<int>& nums) 
    {
        vector<bool> visited(nums.size(), false);
        unordered_map<vector<bool>, int> map;
        return Solve(1, nums, visited, map);

    }

    int Solve(int idx, const vector<int>& nums, vector<bool>& visited, unordered_map<vector<bool>, int>& map)
    {
        if (map.count(visited)) return map[visited];
        int maxVal = 0;
        for (size_t i = 0; i < nums.size() - 1; ++i)
        {
            if (visited[i]) continue;
            for (size_t j = i + 1; j < nums.size(); ++j)
            {
                if (visited[j]) continue;

                // back track
                visited[i] = true;
                visited[j] = true;
                int currVal = idx * GCD(nums[i], nums[j]);
                int nextMaxVal = Solve(idx + 1, nums, visited, map);
                int total = currVal + nextMaxVal;
                maxVal = max(maxVal,total );
                visited[i] = false;
                visited[j] = false;

            }
        }

        return map[visited] = maxVal;


    }


    // Euclidean algorithm
    int GCD(int a, int b)
    {
        while (b != 0)
        {
            int tmp = b;

            b = a % b;

            a = tmp;


        }

        return a;

        
    }
};



int main()
{
    Solution s;
    vector<int> nums = { 3,4,6,8 };
    s.maxScore(nums);
    return 0;
}