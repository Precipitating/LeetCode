#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        if (nums.empty()) return 0;

        int result = 0;
        // store nums to compare easily via key
        unordered_set<int> storedNums = { nums.begin(), nums.end() };


        for (int num: storedNums)
        {
            // only process when we find start of sequence
            if (storedNums.find(num - 1) == storedNums.end())
            {
                int curr = num;
                int currentSeq = 1;
                while (storedNums.find(curr + 1) != storedNums.end())
                {
                    ++currentSeq;
                    ++curr;
                }

                result = max(result, currentSeq);
            }
        
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {};
    s.longestConsecutive(nums);
    return 0;
}