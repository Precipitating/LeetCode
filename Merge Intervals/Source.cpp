#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        vector<vector<int>> result;
        pair<int, int> curr;
        sort(intervals.begin(), intervals.end());

        for (size_t i = 0; i < intervals.size(); ++i)
        {
            curr = make_pair(intervals[i][0],intervals[i][1]);

            for (size_t j = i+1; j < intervals.size(); ++j)
            {
                if (j < intervals.size())
                {
                    if (IsOverlapping(curr, make_pair(intervals[j][0], intervals[j][1])))
                    {
                        curr.first = min(curr.first, intervals[j][0]);
                        curr.second = max(curr.second, intervals[j][1]);
                        ++i;
                    }
                    else
                    {
                        break;
                    }

                }
            }

            result.push_back({curr.first, curr.second});


        }

        return result;

    }

    bool IsOverlapping(const pair<int, int>& set1, const pair<int, int>& set2)
    {
        return ((set1.first >= set2.first) || (set1.second >= set2.first));
    }
};

int main()
{
    Solution s;
    vector<vector<int>> nums = { {1,3}, {2,6},{8,10},{15,18 } };
    //vector<vector<int>> nums = { {1,4 },{0,1 } };
    s.merge(nums);

    return 0;
}