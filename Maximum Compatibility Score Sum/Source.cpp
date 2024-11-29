#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) 
    {
        int result = 0;
        vector<int> usedMentors(students.size(), false);
        Solve(0, 0, students, mentors, usedMentors, result);
        return result;
    }

    void Solve(int idx, int currSum, const vector<vector<int>>& students, const vector<vector<int>>& mentors, vector<int> &usedMentors, int& result)
    {
        if (idx >= students.size())
        {
            result = max(result, currSum);
            return;
        }

        for (size_t i = 0; i < mentors.size(); ++i)
        {
            if (usedMentors[i]) { continue; }
            int currVal = CalculateScore(students[idx], mentors[i]);
            usedMentors[i] = true;
            Solve(idx + 1, currSum + currVal, students, mentors, usedMentors, result);
            usedMentors[i] = false;

        }


    }
    
    int CalculateScore(const vector<int>& student, const vector<int>& mentor)
    {
        int result = 0;
        for (int i = 0; i < student.size(); ++i)
        {
            if (student[i] == mentor[i]) { ++result; }
        }

        return result;

    }
};

int main()
{
    Solution s;
    vector<vector<int>> students = {{1, 1, 0}, {1, 0, 1}, {0, 0, 1}};
    vector<vector<int>> mentors = { {1, 0, 0}, {0, 0, 1}, {1, 1, 0} };
    s.maxCompatibilitySum(students, mentors);
    return 0;
}