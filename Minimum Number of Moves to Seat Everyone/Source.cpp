#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) 
    {
        int result = 0;
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        for (size_t i = 0; i < students.size(); ++i)
        {
            result += abs(seats[i] - students[i]);
        }

        return result;
    }
};

int main()
{
    Solution s;
    vector<int> seats = { 2,2,6,6 };
    vector<int> students = { 1,3,2,6 };
    s.minMovesToSeat(seats, students);
    return 0;
}