#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class KthLargest {
public:

    // O(N∗Log(K))
    KthLargest(int k, vector<int>& nums)
    {
        minElementAllowed = k;
        // push all elements into the queue, but delete the smallest value (top) if it exceeds size k
        // this ensures that the top value will be the k highest value
        for (size_t i = 0; i < nums.size(); ++i)
        {
            minQueue.push(nums[i]);

            if (minQueue.size() > k)
            {
                minQueue.pop();
            }

        }

    }

    int add(int val)
    {
        minQueue.push(val);
        if (minQueue.size() > minElementAllowed)
        {
            minQueue.pop();
        }
        return minQueue.top();

    }


private:
    // this will automatically push the largest element to the bottom of the queue
    // the top of the queue will always be the smallest value
    priority_queue<int,vector<int>, greater<int>> minQueue;
    int minElementAllowed;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */


int main()
{
    int k = 3;
    vector<int> nums = { 4, 5, 8, 2};
    KthLargest* obj = new KthLargest(k, nums);
    int param_1 = obj->add(3);
    int param_2 = obj->add(5);
    int param_3 = obj->add(10);
    int param_4 = obj->add(9);
    int param_5 = obj->add(4);

    cout << param_1 << param_2 << param_3 << param_4 << param_5;
    delete obj;
    return 0;
}
