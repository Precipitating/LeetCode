#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution 
{
public:

    bool IsConnected(const string& s, const string& t)
    {
        int c = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            c += (s[i] != t[i]);
        }
            
        return c == 1;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        vector<vector<string>> result;
        vector<vector<string>> nodes;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        wordSet.erase(beginWord);

        if (wordSet.find(endWord) == wordSet.end())
        {
            return result;
        }

        bool reached = false;
        nodes.push_back({ beginWord });
        while (!wordSet.empty() && !reached)
        {
            vector<string> last = nodes.back();
            vector<string> curr;


            for (size_t i = 0; i < last.size() && !reached; ++i)
            {
                unordered_set<string> visited;
                string from = last[i];

                for (const auto& to : wordSet)
                {
                    if (visited.count(to)) continue;
                    if (!IsConnected(from, to)) continue;

                    if (to == endWord)
                    {
                        reached = true;
                        break;
                    }

                    curr.push_back(to);
                    visited.insert(to);


                }
                // prevent forming cycles so delete
                for (auto& vis : visited)
                {
                    wordSet.erase(vis);
                }

            }
            if (reached) { break; }
            if (curr.empty()) { break; }

            nodes.push_back(curr);
        }

        if (!reached) { return result; }



        result.push_back({endWord});

        // go backwards
        for (int i = nodes.size() - 1; i >= 0; --i)
        {
            int n = result.size();

            while (n > 0)
            {
                vector<string> path = result.back();
                result.pop_back();
                string from = path.front();


                for (const string& to : nodes[i])
                {
                    if (!IsConnected(from, to)) { continue; }

                    vector<string> newPath = path;
                    newPath.insert(newPath.begin(), to);
                    result.insert(result.begin(), newPath);
                }
                --n;
            }
        }
       
        return result;


    }


};


int main()
{
    Solution s;
    string begin = "hit";
    string end = "cog";
    vector<string> wordList = { "hot","dot", "dog", "lot", "log", "cog" };
    s.findLadders(begin, end, wordList);
    return 0;
}
