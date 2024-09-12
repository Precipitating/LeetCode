#include <iostream>
#include <vector>
using namespace std;

class MinStack
{
public:
    MinStack() : minVal(INT_MAX) {}
    void push(int val)
    {
        // if its empty, then clearly we want to reset the minVal
        if (stack.empty()) { minVal = INT_MAX; }
        minVal = min(minVal, val);
        stack.emplace_back(val,minVal);
    }

    void pop()
    {
        stack.pop_back();
        // change minVal to previous if we delete the back
        if (!stack.empty())
        {
            minVal = stack.back().second;
        }

    }

    int top() 
    {
        return stack.back().first;
    }

    int getMin() 
    {
        return stack.back().second;
    }

private:
    vector<pair<int,int>> stack;
    int minVal;
    
};

int main()
{
    MinStack minStack;
    minStack.push(-10);
    minStack.push(14);
    cout << minStack.getMin() << '\n';
    cout << minStack.getMin() << '\n';
    minStack.push(-20);
    cout << minStack.getMin() << '\n';
    cout << minStack.getMin() << '\n';
    minStack.top();
    cout << minStack.getMin() << '\n';
    minStack.pop();
    minStack.push(10);
    minStack.push(-7);
    cout << minStack.getMin() << '\n';
    minStack.push(-7);
    minStack.pop();
    minStack.top();
    cout << minStack.getMin() << '\n';
    minStack.pop();
    


 

    return 0;
}
