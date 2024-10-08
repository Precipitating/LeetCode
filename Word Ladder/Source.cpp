#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;



class Solution 
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        int result = 0;
        // curr string, curr count
        queue<pair<string,int>> q;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        unordered_set<string> visited;
        if (wordSet.find(endWord) == wordSet.end()) { return 0; }

        // start from 1 to include beginWord
        q.emplace(beginWord,1);

        while (!q.empty())
        {
            auto curr = q.front(); q.pop();

            // attempt to bruteforce and swap each character in the string and see if it
            // exists in wordSet

            for (size_t i = 0; i < curr.first.size(); i++)
            {
                for (char first = 'a'; first <= 'z'; ++first)
                {
                    string modifiedStr = curr.first;
                    modifiedStr[i] = first;

                    if (modifiedStr != curr.first)
                    {        
                        // if this modified string exists in set, increase count
                        if (wordSet.find(modifiedStr) != wordSet.end() && visited.find(modifiedStr) == visited.end())
                        {
                            // if endWord, we found the answer, add one to include endWord to length
                            if (modifiedStr == endWord) { return curr.second + 1; }

                            // else add to queue
                            q.push({ modifiedStr, curr.second + 1 });

                            // add to visited to prevent revisit
                            visited.insert(modifiedStr);


                        }
                    }

                }
            }

        }

        return result;

    }

};

int main()
{
    Solution s;
    string beg = "hit";
    string end = "cog";
    vector<string> wordList = { "hot","dot","dog","lot","log" };

    cout << s.ladderLength(beg, end, wordList);
    return 0;
}