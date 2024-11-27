#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    string findDifferentBinaryString(vector<string>& nums) 
    {
        string result;
        unordered_set<string> visited(nums.begin(), nums.end());

        BackTrack(0, "", nums, visited, result);

        return result;
    }

    bool BackTrack(int idx, string curr, const vector<string>& nums, unordered_set<string>& visited, string& result)
    {
        if (idx == nums[0].length())
        {
            if (visited.find(curr) == visited.end())
            {
                result = curr;
                return true;
            }
            return false;
        }

        if (BackTrack(idx + 1, curr + '0', nums, visited, result)) return true;
        if (BackTrack(idx + 1, curr + '1', nums, visited, result)) return true;



        return false;


    }
};

int main()
{
    Solution s;
    vector<string> nums = { "00","01" };
    s.findDifferentBinaryString(nums);
    return 0;
}