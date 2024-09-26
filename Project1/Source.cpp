#include <iostream>
#include <vector>
#include <stack>
using namespace std;

 // This is the interface that allows for creating nested lists.
 // You should not implement it, or speculate about its implementation
 class NestedInteger
 {
   public:
     // Return true if this NestedInteger holds a single integer, rather than a nested list.
     bool isInteger() const;
 
     // Return the single integer that this NestedInteger holds, if it holds a single integer
     // The result is undefined if this NestedInteger holds a nested list
     int getInteger() const;
 
     // Return the nested list that this NestedInteger holds, if it holds a nested list
     // The result is undefined if this NestedInteger holds a single integer
     const vector<NestedInteger> &getList() const;
 };
 

class NestedIterator 
{
public:
    NestedIterator(vector<NestedInteger>& nestedList) 
    {
        // current begin/end iterator.
        nestedStackBegin.push(nestedList.begin());
        nestedStackEnd.push(nestedList.end());

    }

    int next()
    {
        // access next value in stack
        hasNext();
        return nestedStackBegin.top()++->getInteger();
    }

    bool hasNext()
    {
        while (!nestedStackBegin.empty())
        {
            // we're at the end of the current list, so pop it 
            // could be inside a nested list, or not.
            if (nestedStackBegin.top() == nestedStackEnd.top())
            {
                nestedStackBegin.pop();
                nestedStackEnd.pop();
            }
            else
            {
                auto it = nestedStackBegin.top();

                if (it->isInteger())
                {
                    return true;
                }

                nestedStackBegin.top()++;
                // push in the numbers in the nested list to be processed first
                nestedStackBegin.push(it->getList().begin());
                nestedStackEnd.push(it->getList().end());

            }

        }
        return false;
    }

private:
    stack<vector<NestedInteger>::const_iterator> nestedStackBegin, nestedStackEnd;
};


int main()
{

}
/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */