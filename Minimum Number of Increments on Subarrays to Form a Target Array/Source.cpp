#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    int minNumberOperations(vector<int>& target)
    {
        int result = target[0];
        for (size_t i = 1; i < target.size(); ++i)
        {
            result += max(0, target[i] - target[i - 1]);
        }

        return result;
    }

};


int main()
{
    Solution s;
    vector<int> target = { 1,2,3,2,1 };
    s.minNumberOperations(target);

    return 0;
}