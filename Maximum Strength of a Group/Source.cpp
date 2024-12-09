#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    long long maxStrength(vector<int>& nums) 
    {
        Solve(0, 1,false, nums);
        return result;
    }

    void Solve(int idx, long long sum, bool used, const vector<int>& nums)
    {
        if (idx == nums.size())
        {
            if (used)
            {
                result = max(result, sum);
            }

            return;
        }


        Solve(idx + 1, sum * nums[idx],true, nums);
        Solve(idx + 1, sum, used, nums);

        

    }

private:
    long long result = LLONG_MIN;
};

int main()
{
    Solution s;
    vector<int> nums = { -1,-7,-5,7,7,0,9,0,-5,-6 };
    s.maxStrength(nums);
    return 0;
}