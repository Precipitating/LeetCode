#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        int result = 0;
        priority_queue<int, std::vector<int>, std::greater<int>> queue;

        for (size_t i = 0; i < nums.size(); ++i)
        {
            queue.push(nums[i]);
            if (queue.size() > k )
            {
                queue.pop();
            }

        }

        return queue.top();


    }
};


int main()
{
    Solution s;
    vector<int> nums = { 3,2,3,1,2,4,5,5,6 };
    cout << s.findKthLargest(nums, 4);
    return 0;
}
