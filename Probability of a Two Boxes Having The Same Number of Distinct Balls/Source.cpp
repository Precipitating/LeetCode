#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution
{
public:
    double getProbability(vector<int>& balls) 
    {
        vector<int> first(balls.size());
        vector<int> second(balls.size());

        return Probability(0, first, second, balls);
    }
    // calculate total num of ways to arrange balls
    // calculate factorials of total balls / factorials of count of each color
    double CountShuffle(const vector<int>& balls)
    {
        double result = 1;
        double last = 0;

        for (int colour : balls)
        {
            for (size_t i = 1; i <= colour; i++)
            {
                last++;
                result *= last;
                result /= i;
            }
           
        }
        return result;
    }
    double Probability(int idx, vector<int>& first, vector<int>& second, const vector<int>& balls)
    {
        double result = 0.0;
        if (idx == balls.size())
        {
            // if satisfies conditions 
            // same balls and distinct colours
            if (accumulate(first.begin(), first.end(), 0) == accumulate(second.begin(), second.end(), 0) &&
                accumulate(first.begin(), first.end(), 0, [&](int sum, int color) {return sum + (color > 0); }) ==
                accumulate(second.begin(), second.end(), 0, [&](int sum, int color) {return sum + (color > 0); }))
            {
                // return correct probability
                return ( (CountShuffle(first) * CountShuffle(second)) / CountShuffle(balls));

            }
            return 0.0;
        }

        for (size_t i = 0; i <= balls[idx]; ++i)
        {
            // back track
            first[idx] = i;
            second[idx] = balls[idx] - i;
            result += Probability(idx + 1, first, second, balls);
            first[idx] = 0;
            second[idx] = 0;

        }

        return result;



    }
};
int main()
{
    Solution s;
    vector<int> balls = { 2,1,1 };
    s.getProbability(balls);

    return 0;
}