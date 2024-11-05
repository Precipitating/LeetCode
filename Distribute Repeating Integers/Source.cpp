#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution
{
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) 
    {
        bool result = false;
        unordered_map<int, int> numCount;

        for (int num : nums)
        {
            ++numCount[num];
        }

        vector<int> countVec;
        for (const pair<int,int>& count : numCount)
        {
            countVec.push_back(count.second);
        }

        sort(quantity.rbegin(), quantity.rend());

        BackTrack(0, countVec, quantity, result);
        return result;

    }

    void BackTrack(int i, vector<int> &count, vector<int>& quantity, bool& result)
    {
        if (i == quantity.size() || result)
        {
            result = true;
            return;
        }

        for (size_t j = 0; j < count.size(); ++j)
        {
            if (count[j] >= quantity[i])
            {
                count[j] -= quantity[i];
                BackTrack(i + 1, count, quantity, result);
                count[j] += quantity[i];
            }

        }

    }

};


int main()
{
    Solution s;
    vector<int> nums = { 1,2,3,3 };
    vector<int> quantity = { 2 };
    s.canDistribute(nums, quantity);
}