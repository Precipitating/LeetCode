#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class Solution
{
public:
    int minPartitions(string n)
    {
        // it's max digit due to needing 1's to form the max digit in binary form
        return *max_element(n.begin(), n.end()) - '0';

    }
};


int main()
{
    Solution s;
    s.minPartitions("32");
    return 0;
}