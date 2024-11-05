#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;


class Solution 
{
public:
    bool isSolvable(vector<string>& words, string result) 
    {
        for (string& word : words)
        {
            for (int i = word.size() - 1; i >= 0; --i)
            {
                charCount[word[i]] += pow(10, word.size() - 1 - i);
            }
            if (word.size() > 1)
            {
                leadChar.insert(word[0]);
            }
        }

        for (int i = result.size() - 1; i >= 0; --i)
        {
            charCount[result[i]] -= pow(10, result.size() - 1 - i);

        }
        if (result.size() > 1)
        {
            leadChar.insert(result[0]);
        }

        if (charCount.size() > 10) { return false; }
        vector<char> digMap(10, ' ');
        vector<pair<int, char>> candidates;

        for (auto p : charCount)
        {
            candidates.emplace_back(p.second, p.first);

        }
        sort(candidates.begin(), candidates.end(), [](pair<int, char> a, pair<int, char> b)
            {
                return abs(a.first) > abs(b.first);
            });
        

        return BackTrack(0, candidates, 0, digMap);


    }


    bool BackTrack(int sum, const vector<pair<int, char>>& candidates, int candIdx, vector<char>& digMap)
    {
        if (candIdx == candidates.size())
        {
            return (sum == 0);
        }

        // early prune if sum cannot reach 0
        if (abs(sum) > abs(9 * candidates[candIdx].first) * (candidates.size() - candIdx))
        {
            return false;
        }

        for (size_t i = 0; i < 10; ++i)
        {
            if (digMap[i] != ' ') continue;
            if (i == 0 && leadChar.count(candidates[candIdx].second) == 1) continue;
            digMap[i] = candidates[candIdx].second;
            if (BackTrack(sum + i * candidates[candIdx].first, candidates, candIdx + 1, digMap))
            {
                return true;
            }
            digMap[i] = ' ';
        }

        return false;
    }

private:
    unordered_map<char, int> charCount;
    unordered_set<char> leadChar;
    
};


int main()
{
    Solution s;
    vector<string> words = { "SIX","SEVEN","SEVEN" };
    string result = "TWENTY";

    s.isSolvable(words, result);
    return 0;
}