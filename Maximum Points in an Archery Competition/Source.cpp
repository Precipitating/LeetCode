#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) 
    {
        vector<int> result(aliceArrows.size());
        vector<int> curr(aliceArrows.size());
        int maxScore = INT_MIN;

        Solve(0, curr, 0, maxScore, numArrows, aliceArrows, result);

        // Ensure all arrows are used
        int remainingArrows = numArrows;
        for (int arrows : result)
            remainingArrows -= arrows;

        // Assign leftover arrows to the first region arbitrarily
        if (remainingArrows > 0)
            result[0] += remainingArrows;

        return result;
    }

    void Solve(int idx, vector<int>& curr, int score, int& maxScore, int arrowsLeft, const vector<int>& aliceArrows, vector<int>& result)
    {
        if (idx >= aliceArrows.size() || arrowsLeft <= 0)
        {
            if (score > maxScore)
            {
                maxScore = score;
                result = curr;
            }
            return;
        }

        // skip
        Solve(idx + 1,curr, score, maxScore, arrowsLeft, aliceArrows, result);

        // beat alice
        if (arrowsLeft > aliceArrows[idx])
        {
            curr[idx] = aliceArrows[idx] + 1;
            Solve(idx + 1, curr, score + idx, maxScore, arrowsLeft - (aliceArrows[idx] + 1), aliceArrows, result);
            curr[idx] = 0;
        }


        




    }
};


int main()
{
    Solution s;
    vector<int> arrows = { 1,1,0,1,0,0,2,1,0,1,2,0 };
    s.maximumBobPoints(9, arrows);

    return 0;
}