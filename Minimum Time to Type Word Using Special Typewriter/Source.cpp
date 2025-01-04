#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int minTimeToType(string word)
    {
        // takes word.size() seconds to type the character, so all we have to do is worry about
        // the character distance clockwise/anti-clockwise
        int result = word.size();
        char curr = 'a';
        int idx = 0;

        while (curr != word.back() || idx != word.size())
        {
            int clockwiseDiff = abs(curr - word[idx]);
            int counterClockwiseDiff = 26 - clockwiseDiff;
            result += min(clockwiseDiff, counterClockwiseDiff);
            curr = word[idx++];
        }

        return result;

    }
};

int main()
{
    Solution s;
    s.minTimeToType("bza");
    return 0;
}