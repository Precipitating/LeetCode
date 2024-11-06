#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution 
{
public:
    int minimumTimeRequired(vector<int>& jobs, int k) 
    {
        // optimization: assign larger jobs earlier to detect early returns
        sort(jobs.rbegin(), jobs.rend());

        // get hardest job possible and and highest possible for binary search
        int low = *max_element(jobs.begin(), jobs.end());
        int high = accumulate(jobs.begin(), jobs.end(), 0);

        // binary search
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (isPossible(mid, k, jobs))
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }


        return low;

    }

    bool isPossible(int maxTime, int k, const vector<int>& jobs)
    {
        vector<int> workers(k, 0);
        return DFS(0, maxTime, workers, jobs);

    }

    bool DFS(int idx, int maxTime, vector<int>& workerTimes, const vector<int>& jobs)
    {
        if (idx == jobs.size()) { return true; }

        int currentTime = jobs[idx];

        for (size_t i = 0; i < workerTimes.size(); ++i)
        {
            // backtrack
            if (workerTimes[i] + currentTime <= maxTime)
            {
                workerTimes[i] += currentTime;
                if (DFS(idx + 1, maxTime, workerTimes, jobs))
                {
                    return true;
                }
                workerTimes[i] -= currentTime;
            }

            if (workerTimes[i] == 0) { break; }


        }

        return false;
    }

};

int main()
{
    Solution s;
    vector<int> jobs = { 3,2,3 };
    int k = 3;
    s.minimumTimeRequired(jobs, k);

    return 0;
}