#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;


class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        // amount | number
        priority_queue<pair<int,int>> maxHeap;
        unordered_map<int, int> map;
        vector<int> result;


        for (size_t i = 0; i < nums.size(); ++i)
        {
            ++map[nums[i]];
        }

        // priority queue sorts from the first element pair, so swap it around.
        // using built in comparator.
        for (auto it = map.begin(); it != map.end(); ++it)
        {
            maxHeap.push(make_pair(it->second, it->first));
        }

        for (size_t i = 0; i < k; ++i)
        {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 3,0,1,0 };
    s.topKFrequent(nums,1);

    return 0;
}