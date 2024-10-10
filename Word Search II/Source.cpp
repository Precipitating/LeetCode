#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;



class Trie
{
public:
    // Trie
    struct Node
    {
        Node()
        {
            memset(next, 0, sizeof(next));
            isEnd = false;
        }
        ~Node()
        {
            for (int i = 0; i < 26; ++i)
            {
                delete next[i];
            }
        }
        Node* next[26];
        bool isEnd;
    };
    Trie()
    {
        root = new Node();
    }
    ~Trie()
    {
        delete root;
    }


    void insert(string word)
    {
        Node* temp = root;
        // insert word char by char 
        for (const char& c : word)
        {
            char idx = c - 'a';
            if (!temp->next[idx])
            {
                temp->next[idx] = new Node();
            }
            temp = temp->next[idx];
        }
        temp->isEnd = true;
    }

    bool search(string word)
    {
        Node* temp = root;
        for (const char& c : word)
        {
            char idx = c - 'a';
            if (!temp->next[idx]) { return false; }
            temp = temp->next[idx];

        }

        return temp && temp->isEnd;



    }

    bool startsWith(string prefix)
    {
        Node* temp = root;
        for (const char& c : prefix)
        {
            char idx = c - 'a';
            if (!temp->next[idx]) { return false; }
            temp = temp->next[idx];

        }

        return temp;
    }

    Node* getRoot() {
        return root;
    }

private:
    Node* root;
};



class Solution
{
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        vector<string> result;
        unordered_set<string> foundResults;
        Trie* trie = new Trie();

        for (const string& word : words)
        {
            trie->insert(word);
        }

        string word = "";
        for (size_t i = 0; i < board.size(); ++i)
        {
            for (size_t j = 0; j < board[0].size(); ++j)
            {  
                Recurse(i, j,word, board, result, trie->getRoot());
                
            }
        }

        return result;
    }

    void Recurse(int row, int col, string& str, vector<vector<char>>& board, vector<string>& result, Trie::Node* trie)
    {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) { return; }
        if (board[row][col] == '#') { return; }

        int nextCharIdx = (board[row][col] - 'a');
        char temp = board[row][col];

        // if current string doesnt exist in trie, return early
        if (!trie->next[nextCharIdx]) { return; }

        str += temp;
        trie = trie->next[nextCharIdx];

        // if full word found, add to result
        if (trie->isEnd)
        {
            result.push_back(str);
            trie->isEnd = false;

        }
        board[row][col] = '#';
        Recurse(row + 1, col,  str, board, result, trie);
        Recurse(row - 1, col,  str, board, result, trie);
        Recurse(row, col + 1,  str, board, result, trie);
        Recurse(row, col - 1,  str, board, result, trie);
        board[row][col] = temp;
        str.pop_back();

    }
};


int main()
{
    Solution s;
    vector<vector<char>> board = {{'o', 'a', 'b', 'n'}, {'o', 't', 'a', 'e'}, {'a', 'h', 'k', 'r'}, {'a', 'f', 'l', 'v'}};
    vector<string> words = { "oa", "oaa" };
    s.findWords(board, words);
    return 0;
}