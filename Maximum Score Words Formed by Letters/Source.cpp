#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;



class Solution 
{
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score)
    {
        int result = 0;
        vector<int> lettersCount(26,0);
        unordered_map<string, int> wordScore;

        // get count of letters available and store it
        for (char c : letters)
        {
            ++lettersCount[c - 'a'];
        }

        // store score of each word
        for (const string& word : words)
        {
            int currScore = 0;

            for (char c : word)
            {
                currScore += score[c - 'a'];
            }
            wordScore[word] = currScore;
        }


        BackTrack(0,0,result, words, lettersCount, wordScore);



        return result;
    }

    void BackTrack(int idx, int currScore, int& result, const vector<string>& words, vector<int>& lettersCount, unordered_map<string, int>& wordScore)
    {
        if (idx == words.size())
        {
            result = max(result, currScore);
            return;
        }

        bool canForm = true;
        vector<int> wordCount(26, 0);


        // check if we can form this word
        for (char c : words[idx])
        {
            ++wordCount[c - 'a'];
            if (wordCount[c - 'a'] > lettersCount[c - 'a'])
            {
                canForm = false;
                break;
            }


        }


        if (canForm)
        {
            // backtrack
            for (int i = 0; i < 26; i++) 
            {
                lettersCount[i] -= wordCount[i];
            }
            BackTrack(idx + 1, currScore + wordScore[words[idx]], result, words, lettersCount, wordScore);

            for (int i = 0; i < 26; i++)
            {
                lettersCount[i] += wordCount[i];
            }

        }
        // other option, exclude the word instead
        BackTrack(idx + 1, currScore, result, words, lettersCount, wordScore);


    }

};

int main()
{
    Solution s;
    vector<string> words = { "dog","cat","dad","good" };
    vector<char> letters = { 'a','a','c','d','d','d','g','o','o' };
    vector<int> score = { 1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0 };
    s.maxScoreWords(words, letters, score);

    return 0;
}
