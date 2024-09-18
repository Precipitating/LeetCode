#include <iostream>
using namespace std;

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

class Trie
{
public:
    
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

private:
    Node* root;
};


int main()
{
    Trie* s = new Trie();
    s->insert("apple");
    cout << s->search("apple");
    cout << s->search("app");
    cout << s->startsWith("app");
    s->insert("app");
    cout << s->search("app");

    delete s;

    return 0;
}
