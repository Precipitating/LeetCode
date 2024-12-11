#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    int findMinimumTime(vector<int>& strength, int K) 
    {
        // we want to break the smallest lock as fast as possible
        sort(strength.begin(), strength.end());

        Solve(0, 1, K, 0, strength);
        return result;
    }

    void Solve(int temp, int x, int k,int mask, vector<int>& strength)
    {
        // if all strength locks opened we're done
        if (mask == (1 << strength.size()) - 1)
        {
            result = min(result, temp);
            return;
        }

        int sum = x, add = 0;

        for (int i = 0; i < strength.size(); ++i)
        {
            // if idx already visited go next
            if (mask & (1 << i)) { continue; }
            add = (strength[i] + (x - 1)) / x;
            // mask is set visited via OR
            Solve(temp + add, x + k, k, (mask | (1 << i)), strength);
        }

    }
private:
    int result = INT_MAX;
};

int main()
{
    Solution s;
    vector<int> stren = { 3,4,1 };

    s.findMinimumTime(stren, 1);
    return 0;
}