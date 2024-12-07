#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CombinationIterator 
{
public:
    CombinationIterator(string characters, int combinationLength)
    {
        Solve(0, curr, characters, combinationLength);
    
    }

    string next()
    {
        return storedCombi[currPos++];
    }
    void Solve(int idx, string& curr, const string& chars, int len)
    {
        if (curr.size() == len)
        {
            storedCombi.push_back(curr);
            return;
        }
        if (idx >= chars.size()) { return; }
        curr.push_back(chars[idx]);
        Solve(idx + 1, curr, chars, len);
        curr.pop_back();
        Solve(idx + 1, curr, chars, len);

    }

    bool hasNext() 
    {
        return currPos < storedCombi.size();
    }

private:
    string curr;
    vector<string> storedCombi;
    int currPos = 0;

};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main()
{

    CombinationIterator* obj = new CombinationIterator("abc", 2);
    string param_1 = obj->next();
    bool param_2 = obj->hasNext();
    obj->next();
    obj->hasNext();
    obj->next();
    obj->hasNext();
    delete obj;
    return 0;
}
