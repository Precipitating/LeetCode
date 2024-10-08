#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution
{
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        vector<string> result;
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

        BackTrack(0, "", s, wordSet, result);
        return result;

    }

    void BackTrack(int idx, string curr, const string& s, const unordered_set<string>& set, vector<string>& result)
    {
        if (idx >= s.size())
        { 
            // get rid of that extra " "
            curr.pop_back();
            result.push_back(curr);
            result.clear();
            return; 
        }

        for (int i = idx; i < s.size(); ++i)
        {
            string word = s.substr(idx, i - idx + 1);
            if (set.count(word))
            {
                BackTrack(i + 1, curr + word + " ",s, set, result);
            }
        }


    }
};

int main()
{
    Solution s;
    vector<string> dict = { "cat","cats","and","sand","dog" };
    string str = "catsanddog";
    s.wordBreak(str, dict);

    return 0;
}


