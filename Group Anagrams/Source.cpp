#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> map;

        for (size_t i = 0; i < strs.size(); i++)
        {
            string curr = strs[i];
            sort(curr.begin(), curr.end());
            map[curr].push_back(strs[i]);

        }
        result.reserve(map.size());
        for (auto& elem : map)
        {
            result.push_back(std::move(elem.second));
        }

        return result;
    }
};

int main()
{
    Solution s;
    vector<string> strs = { "eat","tea","tan","ate","nat","bat" };
    s.groupAnagrams(strs);
    return 0;
}