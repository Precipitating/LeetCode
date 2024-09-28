#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    Solution(vector<int>& nums) 
    {
        vec = nums;
        originalConfig = nums;
    }

    vector<int> reset() 
    {
        vec = originalConfig;
        return vec;
    }

    vector<int> shuffle() 
    {
        // in place, Knuth Shuffle

        // start with last element in vec
        int last = vec.size() - 1;
        for (int i = last; i > 0; --i)
        {
            int randomIdx = rand() % (i + 1);
            swap(vec[i], vec[randomIdx]);

        }

        return vec;

    }

private:
    vector<int> originalConfig;
    vector<int> vec;
};

int main()
{
    vector<int> nums = { 0,-12893,128384 };
    Solution s(nums);
    s.shuffle();
    s.shuffle();
    s.shuffle();
    s.shuffle();
    return 0;
}
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */