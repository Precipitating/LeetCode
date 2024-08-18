#include <iostream>
#include <stack>
using namespace std;


struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    ~ListNode() { delete next; }
};

class Solution
{
public:
    bool isPalindrome(ListNode* head)
    {
        bool result = true;

        stack<int> numberList;
        int listSize = GetListSize(head, 0);
        int idx = 0;
        bool isOdd = false;

        if (listSize % 2 != 0)
        {    
            isOdd = true;
        }
        listSize /= 2;



        while (head != nullptr)
        {
            if (idx < listSize)
            {
                numberList.push(head->val);

            }
            else
            {
                if (!isOdd || idx != listSize)
                {
                    if (head->val != numberList.top())
                    {
                        result = false;
                        break;
                    }
                    else
                    {
                        numberList.pop();
                    }
                }

            }
            ++idx;
            head = head->next;
        }

        return result;
    }

    int GetListSize(ListNode* head, int maxSize)
    {
        if (head != nullptr)
        {
            maxSize = max(maxSize, GetListSize(head->next, maxSize + 1));
        } 

        return maxSize;
    }
};

int main()
{
    Solution s;
    ListNode* node = new ListNode(1, new ListNode(5));
    cout << s.isPalindrome(node);


    delete node;

    return 0;
}