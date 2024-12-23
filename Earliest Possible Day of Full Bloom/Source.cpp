#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime)
    {
        int result = 0;
        vector<pair<int, int>> plantPairs;

        for (size_t i = 0; i < plantTime.size(); ++i)
        {
            plantPairs.emplace_back(growTime[i], plantTime[i]);

        }
        sort(plantPairs.rbegin(), plantPairs.rend());

        int currPlantTime = 0;
        for (const pair<int, int>& plant : plantPairs)
        {
            currPlantTime += plant.second;

            int bloomTime = currPlantTime + plant.first;

            result = max(result, bloomTime);


        }


        return result;



    }
};

int main()
{
    Solution s;
    vector<int> plant = { 1,4,3 };
    vector<int> bloom = { 2,3,1};
    s.earliestFullBloom(plant, bloom);

    return 0;
}