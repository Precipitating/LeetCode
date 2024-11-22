#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution 
{
public:
    vector<int> splitIntoFibonacci(string num)
    {
        vector<int> result;
        BackTrack(0, num, result);

        return result;

    }

    bool BackTrack(int idx, const string& num, vector<int>& result)
    {
        if (idx == num.size() ) 
        { 
            return result.size() >= 3;
        }

        long long numCheck = 0;
        for (size_t i = idx; i < num.size(); ++i)
        {
            // no leading zeroes allowed
            if (num[idx] == '0' && i > idx) { break; }

            // build up the number efficiently (not using substr)
            numCheck = numCheck * 10 + (num[i] - '0');

            // no overflow allowed
            if (numCheck > INT_MAX || numCheck < 0) { break; }

            int n = result.size();
            // if prev 2 nums are > then its not a valid sequence
            if (n >= 2 && numCheck > (long long)result[n - 1] + (long long)result[n - 2])
            {
                break;
            }
            // add to result and backtrack to next idx
            if (n <= 1 || (long long)result[n - 1] + (long long)result[n - 2] == numCheck)
            {
                result.push_back((int)numCheck);
                if (BackTrack(i + 1, num, result)) { return true; }
                result.pop_back();
            }


        }

        return false;

    }

};


int main()
{
    Solution s;
    s.splitIntoFibonacci("214748364721474836422147483641");
    return 0;
}