#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> addOperators(string num, int target) 
    {
        vector<string> result;
        BackTrack(0,0,"", num, 0, target, result);
        return result;
    }

    void BackTrack(long curr, int idx, string currStr, const string& num, long multiply, int target, vector<string>& result)
    {
        if (idx == num.size())
        {
            if (curr == target)
            {
                result.push_back(currStr);
            }
            return;
        }

        for (size_t i = idx; i < num.size(); ++i)
        {
            if (i > idx && num[idx] == '0') { break; }
            // convert to num
            long toLong = stoll(num.substr(idx, i - idx + 1));

            if (idx == 0)
            {
                BackTrack(toLong, i + 1, currStr + to_string(toLong), num, toLong, target, result);
            }
            else
            {

                BackTrack(curr + toLong, i + 1, currStr + "+" + to_string(toLong), num, toLong, target, result);
                BackTrack(curr - toLong, i + 1, currStr + "-" + to_string(toLong), num, -toLong, target, result);
                BackTrack(curr - multiply + multiply * toLong, i + 1, currStr + "*" + to_string(toLong), num, multiply * toLong, target, result);

            }

        }

    }
};




int main()
{
    Solution s;
    string str = "123";
    int target = 6;
    s.addOperators(str, target);
    return 0;
}