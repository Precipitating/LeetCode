#include <iostream>
#include <vector>
using namespace std;

// TLE O(n^2)
//class Solution
//{
//public:
//    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
//    {
//        bool result = false;
//        int answer = -1;
//        for (size_t i = 0; i < gas.size(); ++i)
//        {
//            CheckCurrentStation(i, i, 0, gas[i], gas, cost, result);
//
//            if (result) { answer = i; break; }
//        }
//
//        return answer;
//    }
//    
//    void CheckCurrentStation(int currIdx, int target, int targetCnt, int tank, const vector<int>& gas, const vector<int>& cost, bool& result)
//    {   
//        if (result) { return; }
//        int currNet = tank - cost[currIdx];
//        if (currNet < 0) { return; }
//        if (currIdx == target) { ++targetCnt; }
//        if (currIdx == target && targetCnt == 2) { result = true; }
//
//
//
//        int next = (currIdx + 1) % gas.size();
//        CheckCurrentStation(next, target, targetCnt, currNet + gas[(currIdx + 1) % gas.size()], gas, cost, result);
//    }
//};

// One pass o(N)
class Solution
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        bool result = false;
        int totalGas = 0;
        int currGas = 0;
        int answer = 0;
        for (size_t i = 0; i < gas.size(); ++i)
        {
            int currentStationCost = gas[i] - cost[i];

            totalGas += currentStationCost;
            currGas += currentStationCost;
            if (currGas < 0)
            {
                answer = i + 1;
                currGas = 0;
            }
        }

        if (totalGas < 0) { answer = -1; }

        return answer;
    }

};
int main()
{
    Solution s;
    vector<int> gas = { 1,2,3,4,5 };
    vector<int> cost = { 3,4,5,1,2 };
    cout << s.canCompleteCircuit(gas, cost);

    return 0;
}