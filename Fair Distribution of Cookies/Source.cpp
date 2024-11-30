#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    int distributeCookies(vector<int>& cookies, int k)
    {
        int result = INT_MAX;
        vector<int> curr(k, 0);
        Solve(0, curr, cookies, k, result);
        return result;
    }

    void Solve(int idx, vector<int>& curr, vector<int>& cookies, int k, int& result)
    {
        if (idx == cookies.size())
        {
            int maxVal = INT_MIN;

            for (size_t i = 0; i < k; ++i)
            {
                maxVal = max(maxVal, curr[i]);
            }
            result = min(result, maxVal);
            return;
        }

        for (int i = 0; i < k; ++i)
        {
            curr[i] += cookies[idx];
            Solve(idx + 1, curr, cookies, k, result);
            curr[i] -= cookies[idx];
            if (curr[i] == 0) { break; }
        }


    }
};

int main()
{
    Solution s;
    vector<int> cookies = { 8,15,10,20,8 };
    s.distributeCookies(cookies, 2);
    return 0;
}